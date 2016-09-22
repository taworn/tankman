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
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
	SDL_Log("SceneWin::~SceneWin()");
}

SceneWin::SceneWin()
{
	SDL_Log("SceneWin::SceneWin()");
	Game *game = Game::instance();
	surface = TTF_RenderUTF8_Solid(game->getFontLarge(), "You Win", { 0xFF, 0xFF, 0x80 });
	texture = SDL_CreateTextureFromSurface(game->getRenderer(), surface);
}

void SceneWin::handleActivate(bool active)
{
	SDL_Log("SceneWin::handleActivate(%d)", active);
}

void SceneWin::handleKey(SDL_KeyboardEvent key)
{
	SDL_Log("SceneWin::handleKey(%d)", key.keysym.sym);
}

void SceneWin::render(int timeUsed)
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

