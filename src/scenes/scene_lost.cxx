/**
 * @file scene_lost.cxx
 * @desc Lost scene module.
 */
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "../game.hxx"
#include "scene.hxx"
#include "scene_lost.hxx"

SceneLost::~SceneLost()
{
}

SceneLost::SceneLost()
{
}

void SceneLost::handleActivate(bool active)
{
	SDL_Log("SceneLost::handleActivate(%d)", active);
}

void SceneLost::handleKey(SDL_KeyboardEvent key)
{
	SDL_Log("SceneLost::handleKey(%d)", key.keysym.sym);
}

void SceneLost::render()
{
}

