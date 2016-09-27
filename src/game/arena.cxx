/**
 * @file arena.cxx
 * @desc Battle area module.
 */
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "../game.hxx"
#include "common.hxx"

Arena::~Arena()
{
	if (spriteMap != NULL)
		delete spriteMap;
	SDL_Log("Arena::~Arena()");
}

Arena::Arena()
	: score(0), stage(0)
	, spriteMap(NULL)
	, map(NULL)
{
	SDL_Log("Arena::Arena()");
	spriteMap = new Sprite(Game::instance()->getRenderer(), TANK_RES("map.png"), 4, 4);
}

void Arena::startBattle()
{
	if (map != NULL)
		delete map;
	map = new Map();
	map->load(TANK_RES("debug0.map"));
}

void Arena::draw()
{
	Game *game = Game::instance();
	SDL_Renderer *renderer = game->getRenderer();

	int imageIndex = 0;
	int w, h;
	SDL_GetRendererOutputSize(renderer, &w, &h);

	int cellX = w / 32;
	int cellY = h / 32;
	for (int j = 0; j < cellY; j++) {
		for (int i = 0; i < cellX; i++) {
			SDL_Rect rect;
			rect.x = i * 32;
			rect.y = j * 32;
			rect.w = 32;
			rect.h = 32;
			
			spriteMap->draw(renderer, imageIndex, &rect);
			
			imageIndex++;
			if (imageIndex >= spriteMap->getImageCount())
				imageIndex = 0;
		}
	}
}

