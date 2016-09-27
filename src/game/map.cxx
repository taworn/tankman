/**
 * @file map.cxx
 * @desc Map module.
 */
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "../game.hxx"
#include "common.hxx"
#include <stdio.h>

Map::~Map()
{
	if (blockData)
		delete[] blockData;
}

Map::Map()
	: width(), height()
	, startHero()
	, blockData()
{
}

bool Map::load(const char *fileName)
{
	// opens file
	SDL_RWops *fp = SDL_RWFromFile(fileName, "rb");
	if (!fp) {
		SDL_Log("Cannot open file.");
		return false;
	}

	// checks file header, 8 bytes
        // header=TANK####, # = ASCII 0
        char check[8] = { 0x54, 0x41, 0x4E, 0x4B, 0x00, 0x00, 0x00, 0x00, };
	char header[8] = { 0 };
	if (SDL_RWread(fp, header, 1, 8) != 8) {
		SDL_Log("Header is not acceptable.");
		SDL_RWclose(fp);
		return false;
	}
	for (int i = 0; i < 8; i++) {
		if (header[i] != check[i]) {
			SDL_Log("Header is not acceptable.");
			SDL_RWclose(fp);
			return false;
		}
	}

	// reads header information
	// 4 int = width, height, hero x and hero y
	int32_t buffer[4] = { 0 };
	if (SDL_RWread(fp, buffer, sizeof(int32_t), 4) != 4) {
		SDL_Log("Not enough data to read.");
		SDL_RWclose(fp);
		return false;
	}
	int w = buffer[0];
	int h = buffer[1];
	int x = buffer[2];
	int y = buffer[3];

	// reads block data
	size_t size = w * h;
	int32_t *blockData = new int32_t[size];
	if (SDL_RWread(fp, blockData, sizeof(int32_t), size) != size) {
		SDL_Log("Not enough data to read.");
		SDL_RWclose(fp);
		return false;
	}

	// closes file
	SDL_RWclose(fp);

	// copying
	this->width = w;
	this->height = h;
	this->startHero.x = x;
	this->startHero.y = y;
	if (this->blockData)
		delete[] this->blockData;
	this->blockData = blockData;

	return true;
}

