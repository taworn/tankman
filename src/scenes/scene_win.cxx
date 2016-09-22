/**
 * @file scene_win.cxx
 * @desc Win scene module.
 */
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "../game.hxx"
#include "scene.hxx"
#include "scene_win.hxx"

SceneWin::~SceneWin()
{
}

SceneWin::SceneWin()
{
}

void SceneWin::handleActivate(bool active)
{
	SDL_Log("SceneWin::handleActivate(%d)", active);
}

void SceneWin::handleKey(SDL_KeyboardEvent key)
{
	SDL_Log("SceneWin::handleKey(%d)", key.keysym.sym);
}

void SceneWin::render()
{
}

