/**
 * @file game.cxx
 * @desc Game framework module.
 */
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "game.hxx"
#include "scenes/scene.hxx"
#include "scenes/scene_title.hxx"
#include "scenes/scene_stage.hxx"
#include "scenes/scene_play.hxx"
#include "scenes/scene_lost.hxx"
#include "scenes/scene_win.hxx"
#include "game/common.hxx"
#include <stdio.h>

Game *Game::singleton = NULL;

Game::~Game()
{
	// deletes current scene
	delete scene;

	// deletes arena
	delete arena;

	// closes fonts
	TTF_CloseFont(fontLarge);
	TTF_CloseFont(fontMedium);
	TTF_CloseFont(fontSmall);

	// destroys renderer
	SDL_DestroyRenderer(renderer);

	// destroys window
	SDL_DestroyWindow(window);
}

Game::Game()
	: window(NULL), renderer(NULL), surfaceWindow(NULL)
	, fontSmall(NULL), fontMedium(NULL), fontLarge(NULL)
	, scene(NULL), nextSceneId(SCENE_TITLE)
{
	SDL_assert(singleton == NULL);
	singleton = this;

	// creates window
	window = SDL_CreateWindow("Tankman", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1024, 768, 0);

	// creates renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	// gets the window surface
	surfaceWindow = SDL_GetWindowSurface(window);

	// opens fonts
	fontSmall = TTF_OpenFont(".\\res\\freefont\\FreeSans.ttf", 24);
	fontMedium = TTF_OpenFont(".\\res\\freefont\\FreeSans.ttf", 32);
	fontLarge = TTF_OpenFont(".\\res\\freefont\\FreeSerifBold.ttf", 64);

	// creates arena
	arena = new Arena();
}

void Game::changeScene(int sceneId)
{
	SDL_Log("changeScene() called, sceneId = %d", sceneId);
	nextSceneId = sceneId;
}

void Game::switchScene()
{
	SDL_Log("perform switchScene() called, sceneId = %d", nextSceneId);
	if (scene)
		delete scene;

	switch (nextSceneId) {
	default:
	case SCENE_DEFAULT:
		scene = new Scene();
		break;
	case SCENE_TITLE:
		scene = new SceneTitle();
		break;
	case SCENE_STAGE:
		scene = new SceneStage();
		break;
	case SCENE_PLAY:
		scene = new ScenePlay();
		break;
	case SCENE_LOST:
		scene = new SceneLost();
		break;
	case SCENE_WIN:
		scene = new SceneWin();
		break;
	}
	nextSceneId = -1;
}

void Game::run()
{
	SDL_Event e;
	unsigned int fpsLast = SDL_GetTicks();
	unsigned int fpsTime = 0;
	unsigned int timeLast = SDL_GetTicks();
	unsigned int timeUsed = SDL_GetTicks() - timeLast;
	bool active = false;
	bool exit = false;

	SDL_Log("start");

	while (!exit) {
		if (active) {
			// clears screen
			SDL_RenderClear(renderer);

			// render current scene
			timeUsed = SDL_GetTicks() - timeLast;
			timeLast = SDL_GetTicks();
			if (nextSceneId < 0)
				scene->render(timeUsed);
			else
				switchScene();

			// computes FPS
			fps = SDL_GetTicks() - fpsLast;
			fps = fps > 0 ? 1000 / fps : 1000;
			fpsLast = SDL_GetTicks();
			if (fpsLast - fpsTime > 1000) {
				SDL_Log("%u fps", fps);
				fpsTime = fpsLast;
			}

			// draws FPS
			char fpsBuffer[16];
			sprintf(fpsBuffer, "%u", fps);
			SDL_Surface *surfaceFPS = TTF_RenderUTF8_Solid(fontSmall, fpsBuffer, { 0x80, 0x80, 0x80 });
			SDL_Texture *textureFPS = SDL_CreateTextureFromSurface(renderer, surfaceFPS);
			SDL_Rect rect;
			rect.x = surfaceWindow->w - surfaceFPS->w;
			rect.y = surfaceWindow->h - surfaceFPS->h;
			rect.w = surfaceFPS->w;
			rect.h = surfaceFPS->h;
			SDL_RenderCopy(renderer, textureFPS, NULL, &rect);
			SDL_DestroyTexture(textureFPS);
			SDL_FreeSurface(surfaceFPS);

			// outputs to screen
			SDL_RenderPresent(renderer);
		}

		// polls events until queue empty
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_KEYDOWN) {
				if (scene)
					scene->handleKey(e.key);
				if (e.key.keysym.sym == SDLK_ESCAPE)
					exit = true;
			}
			else if (e.type == SDL_WINDOWEVENT) {
				if (e.window.event == SDL_WINDOWEVENT_FOCUS_GAINED) {
					SDL_Log("window gained focus");
					active = true;
					if (scene)
						scene->handleActivate(active);
					timeLast = SDL_GetTicks();
				}
				else if (e.window.event == SDL_WINDOWEVENT_FOCUS_LOST) {
					SDL_Log("window lost focus");
					active = false;
					if (scene)
						scene->handleActivate(active);
				}
			}
			else if (e.type == SDL_QUIT) {
				exit = true;
			}
		}
	}

	SDL_Log("exit");
}

