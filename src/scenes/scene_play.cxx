/**
 * @file scene_play.cxx
 * @desc Play scene module.
 */
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "../game.hxx"
#include "scene.hxx"
#include "scene_play.hxx"
#include "../game/common.hxx"

ScenePlay::~ScenePlay()
{
	SDL_Log("ScenePlay::~ScenePlay()");
}

ScenePlay::ScenePlay()
{
	SDL_Log("ScenePlay::ScenePlay()");
}

void ScenePlay::handleActivate(bool active)
{
	SDL_Log("ScenePlay::handleActivate(%d)", active);
}

void ScenePlay::handleKey(SDL_KeyboardEvent key)
{
	SDL_Log("ScenePlay::handleKey(%d)", key.keysym.sym);
	if (key.keysym.sym == SDLK_l)
		Game::instance()->changeScene(Game::SCENE_LOST);
	else if (key.keysym.sym == SDLK_w)
		Game::instance()->changeScene(Game::SCENE_WIN);
}

void ScenePlay::render(int timeUsed)
{
}
