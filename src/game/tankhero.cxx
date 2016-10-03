/**
 * @file tankhero.cxx
 * @desc Tank hero module.
 */
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "../game.hxx"
#include "common.hxx"

TankHero::TankHero()
{
}

void TankHero::init(int x, int y)
{
	setAction(ACTION_MOVE_UP);
	setXY(x, y);
	setTimes(250, 150);
	setROF(200);
	getAni()->add(ACTION_MOVE_LEFT, 2, 4, Animation::ON_END_CONTINUE, getTimePerMove());
	getAni()->add(ACTION_MOVE_RIGHT, 6, 8, Animation::ON_END_CONTINUE, getTimePerMove());
	getAni()->add(ACTION_MOVE_UP, 0, 2, Animation::ON_END_CONTINUE, getTimePerMove());
	getAni()->add(ACTION_MOVE_DOWN, 4, 6, Animation::ON_END_CONTINUE, getTimePerMove());
	getAni()->use(ACTION_MOVE_UP);
}

