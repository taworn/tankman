/**
 * @file bullet.cxx
 * @desc Bullet module.
 */
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "../game.hxx"
#include "common.hxx"

Bullet::~Bullet()
{
}

Bullet::Bullet(int x, int y, int dir)
	: direction(dir)
{
	point.x = x;
	point.y = y;
	if (direction == Movable::ACTION_MOVE_LEFT)
		imageIndex = 1;
	else if (direction == Movable::ACTION_MOVE_RIGHT)
		imageIndex = 3;
	else if (direction == Movable::ACTION_MOVE_UP)
		imageIndex = 0;
	else if (direction == Movable::ACTION_MOVE_DOWN)
		imageIndex = 2;
}

void Bullet::play(int timeUsed)
{
	if (direction == Movable::ACTION_MOVE_LEFT) {
		point.x -= 4;
	}
	else if (direction == Movable::ACTION_MOVE_RIGHT) {
		point.x += 4;
	}
	else if (direction == Movable::ACTION_MOVE_UP) {
		point.y -= 4;
	}
	else if (direction == Movable::ACTION_MOVE_DOWN) {
		point.y += 4;
	}
}

void Bullet::draw(SDL_Renderer *renderer, Sprite *spriteMisc, SDL_Rect *viewport, int timeUsed)
{
	SDL_Point point;
	point.x = this->point.x - viewport->x;
	point.y = this->point.y - viewport->y;

	SDL_Rect rect;
	rect.x = point.x - 16;
	rect.y = point.y - 16;
	rect.w = 32;
	rect.h = 32;
	spriteMisc->draw(renderer, imageIndex, &rect);
}

