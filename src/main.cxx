#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	// initializes SDL
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	TTF_Init();

	// creates window
	SDL_Window *window = SDL_CreateWindow("SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);

	// creates renderer
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	// gets the window surface
	SDL_Surface *surfaceWindow = SDL_GetWindowSurface(window);

	// opens fonts
	TTF_Font *fontSmall = TTF_OpenFont(".\\res\\freefont\\FreeSans.ttf", 24);
	TTF_Font *fontMedium = TTF_OpenFont(".\\res\\freefont\\FreeSans.ttf", 32);
	TTF_Font *fontLarge = TTF_OpenFont(".\\res\\freefont\\FreeSerifBold.ttf", 64);

	// draws title to surface and creates texture
	SDL_Surface *surfaceTitle = TTF_RenderUTF8_Solid(fontLarge, "Tankman", { 0x80, 0xCC, 0x80 });
	SDL_Texture *textureTitle = SDL_CreateTextureFromSurface(renderer, surfaceTitle);

	// draws menu to surface and creates texture
	SDL_Surface *surfaceMenu = TTF_RenderUTF8_Solid(fontMedium, "Press ESC to EXIT", { 0xFF, 0xFF, 0xFF });
	SDL_Texture *textureMenu = SDL_CreateTextureFromSurface(renderer, surfaceMenu);

	// loads image to surface and creates texture
	SDL_Surface *surfaceImage = IMG_Load(".\\res\\tank.png");
	SDL_Texture *textureImage = SDL_CreateTextureFromSurface(renderer, surfaceImage);

	// loop
	SDL_Event e;
	SDL_Rect rect;
	unsigned int fps = SDL_GetTicks();
	unsigned int fpsLast = SDL_GetTicks();
	unsigned int fpsTime = 0;
	int imageX = 0;
	bool exit = false;
	while (!exit) {
		// gets width and height of renderer
		int w, h;
		SDL_GetRendererOutputSize(renderer, &w, &h);

		// clears screen
		SDL_RenderClear(renderer);

		// draws title
		rect.x = (w - surfaceTitle->w) / 2;
		rect.y = (h - surfaceTitle->h) / 2 - surfaceTitle->h - 32;
		rect.w = surfaceTitle->w;
		rect.h = surfaceTitle->h;
		SDL_RenderCopy(renderer, textureTitle, NULL, &rect);

		// draws menu
		rect.x = (w - surfaceMenu->w) / 2;
		rect.y = (h - surfaceMenu->h) / 2 + surfaceMenu->h * 2 + 64;
		rect.w = surfaceMenu->w;
		rect.h = surfaceMenu->h;
		SDL_RenderCopy(renderer, textureMenu, NULL, &rect);

		// draws image
		rect.x = imageX;
		rect.y = (h - surfaceImage->h) / 2;
		rect.w = surfaceImage->w;
		rect.h = surfaceImage->h;
		imageX += 4;
		if (imageX > w)
			imageX = 0;
		SDL_RenderCopy(renderer, textureImage, NULL, &rect);

		// computes FPS
		fps = SDL_GetTicks() - fpsLast;
		fps = fps > 0 ? 1000 / fps : 1000;
		fpsLast = SDL_GetTicks();
		if (fpsLast - fpsTime > 1000) {
			SDL_Log("%u fps", fps);
			fpsTime = fpsLast;
		}

		// draws FPS
		char fpsBuffer[16];
		sprintf(fpsBuffer, "%u", fps);
		SDL_Surface *surfaceFPS = TTF_RenderUTF8_Solid(fontSmall, fpsBuffer, { 0x80, 0x80, 0x80 });
		SDL_Texture *textureFPS = SDL_CreateTextureFromSurface(renderer, surfaceFPS);
		rect.x = surfaceWindow->w - surfaceFPS->w;
		rect.y = surfaceWindow->h - surfaceFPS->h;
		rect.w = surfaceFPS->w;
		rect.h = surfaceFPS->h;
		SDL_RenderCopy(renderer, textureFPS, NULL, &rect);
		SDL_DestroyTexture(textureFPS);
		SDL_FreeSurface(surfaceFPS);

		// outputs to screen
		SDL_RenderPresent(renderer);

		// polls events until queue empty
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_KEYDOWN) {
				if (e.key.keysym.sym == SDLK_ESCAPE)
					exit = true;
			}
			if (e.type == SDL_QUIT) {
				exit = true;
			}
		}
	}

	// destroys texture and free surface
	SDL_DestroyTexture(textureImage);
	SDL_FreeSurface(surfaceImage);

	// destroys texture and free surface
	SDL_DestroyTexture(textureMenu);
	SDL_FreeSurface(surfaceMenu);

	// destroys texture and free surface
	SDL_DestroyTexture(textureTitle);
	SDL_FreeSurface(surfaceTitle);

	// closes fonts
	TTF_CloseFont(fontLarge);
	TTF_CloseFont(fontMedium);
	TTF_CloseFont(fontSmall);

	// destroys renderer
	SDL_DestroyRenderer(renderer);

	// destroys window
	SDL_DestroyWindow(window);

	// uninitializes SDL
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
	return 0;
}

