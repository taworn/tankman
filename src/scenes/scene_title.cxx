/**
 * @file scene_title.cxx
 * @desc Title scene module.
 */
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "../game.hxx"
#include "scene.hxx"
#include "scene_title.hxx"

SceneTitle::~SceneTitle()
{
	SDL_DestroyTexture(textureImage);
	SDL_FreeSurface(surfaceImage);
	SDL_DestroyTexture(textureMenu);
	SDL_FreeSurface(surfaceMenu);
	SDL_DestroyTexture(textureTitle);
	SDL_FreeSurface(surfaceTitle);
}

SceneTitle::SceneTitle()
{
	Game *game = Game::instance();
	surfaceTitle = TTF_RenderUTF8_Solid(game->getFontLarge(), "Tankman", { 0x80, 0xCC, 0x80 });
	textureTitle = SDL_CreateTextureFromSurface(game->getRenderer(), surfaceTitle);
	surfaceMenu = TTF_RenderUTF8_Solid(game->getFontMedium(), "Press ESC to EXIT", { 0xFF, 0xFF, 0xFF });
	textureMenu = SDL_CreateTextureFromSurface(game->getRenderer(), surfaceMenu);
	surfaceImage = IMG_Load(".\\res\\tank.png");
	textureImage = SDL_CreateTextureFromSurface(game->getRenderer(), surfaceImage);
	imageX = 0;
}

void SceneTitle::handleActivate(bool active)
{
	SDL_Log("SceneTitle::handleActivate(%d)", active);
}

void SceneTitle::handleKey(SDL_KeyboardEvent key)
{
	SDL_Log("SceneTitle::handleKey(%d)", key.keysym.sym);
	if (key.keysym.sym == SDLK_RETURN)
		Game::instance()->changeScene(Game::SCENE_DEFAULT);
}

void SceneTitle::render()
{
	Game *game = Game::instance();
	SDL_Rect rect;

	// gets width and height of renderer
	int w, h;
	SDL_GetRendererOutputSize(game->getRenderer(), &w, &h);

	// draws title
	rect.x = (w - surfaceTitle->w) / 2;
	rect.y = (h - surfaceTitle->h) / 2 - surfaceTitle->h - 64;
	rect.w = surfaceTitle->w;
	rect.h = surfaceTitle->h;
	SDL_RenderCopy(game->getRenderer(), textureTitle, NULL, &rect);

	// draws menu
	rect.x = (w - surfaceMenu->w) / 2;
	rect.y = (h - surfaceMenu->h) / 2 + surfaceMenu->h * 2 + 64;
	rect.w = surfaceMenu->w;
	rect.h = surfaceMenu->h;
	SDL_RenderCopy(game->getRenderer(), textureMenu, NULL, &rect);

	// draws image
	rect.x = imageX;
	rect.y = (h - surfaceImage->h) / 2;
	rect.w = surfaceImage->w;
	rect.h = surfaceImage->h;
	imageX += 4;
	if (imageX > w)
		imageX = 0;
	SDL_RenderCopy(game->getRenderer(), textureImage, NULL, &rect);
}

