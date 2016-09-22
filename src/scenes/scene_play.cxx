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

ScenePlay::~ScenePlay()
{
}

ScenePlay::ScenePlay()
{
}

void ScenePlay::handleActivate(bool active)
{
	SDL_Log("ScenePlay::handleActivate(%d)", active);
}

void ScenePlay::handleKey(SDL_KeyboardEvent key)
{
	SDL_Log("ScenePlay::handleKey(%d)", key.keysym.sym);
}

void ScenePlay::render()
{
}

