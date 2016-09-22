/**
 * @file scene_stage.cxx
 * @desc Stage scene module.
 */
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "../game.hxx"
#include "scene.hxx"
#include "scene_stage.hxx"

SceneStage::~SceneStage()
{
}

SceneStage::SceneStage()
{
}

void SceneStage::handleActivate(bool active)
{
	SDL_Log("SceneStage::handleActivate(%d)", active);
}

void SceneStage::handleKey(SDL_KeyboardEvent key)
{
	SDL_Log("SceneStage::handleKey(%d)", key.keysym.sym);
}

void SceneStage::render()
{
}

