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
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
	SDL_Log("SceneLost::~SceneLost()");
}

SceneLost::SceneLost()
{
	SDL_Log("SceneLost::SceneLost()");
	Game *game = Game::instance();
	surface = TTF_RenderUTF8_Solid(game->getFontLarge(), "Game Over", { 0xFF, 0x80, 0x40 });
	texture = SDL_CreateTextureFromSurface(game->getRenderer(), surface);
}

void SceneLost::handleActivate(bool active)
{
	SDL_Log("SceneLost::handleActivate(%d)", active);
}

void SceneLost::handleKey(SDL_KeyboardEvent key)
{
	SDL_Log("SceneLost::handleKey(%d)", key.keysym.sym);
}

void SceneLost::render(int timeUsed)
{
	Game *game = Game::instance();
	SDL_Rect rect;
	int w, h;
	SDL_GetRendererOutputSize(game->getRenderer(), &w, &h);

	rect.x = (w - surface->w) / 2;
	rect.y = (h - surface->h) / 2;
	rect.w = surface->w;
	rect.h = surface->h;
	SDL_RenderCopy(game->getRenderer(), texture, NULL, &rect);
}

