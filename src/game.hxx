/**
 * @file game.hxx
 * @desc Game framework header.
 */
#ifndef GAME_HXX
#define GAME_HXX

class Scene;
class Arena;

/**
 * A simple game framework class.
 */
class Game
{
public:
	static Game* instance() { return singleton; }

	static const int SCENE_DEFAULT = 0;
	static const int SCENE_TITLE = 1;
	static const int SCENE_STAGE = 2;
	static const int SCENE_PLAY = 3;
	static const int SCENE_LOST = 4;
	static const int SCENE_WIN = 5;

	/**
	 * Destructs the game framework.
	 */
	~Game();

	/**
	 * Constructs the game framework.
	 */
	Game();

	/**
	 * Gets current arena.
	 */
	Arena* getArena() { return arena; }

	/**
	 * Changes the new scene.
	 * @param sceneId A scene identifier, look at SCENE_*.
	 */
	void changeScene(int sceneId);

	/**
	 * Gets current scene.
	 */
	Scene* currentScene() { return scene; }

	SDL_Window* getWindow() const { return window; }
	SDL_Renderer* getRenderer() const { return renderer; }
	SDL_Surface* getSurfaceWindow() const { return surfaceWindow; }
	TTF_Font* getFontSmall() const { return fontSmall; }
	TTF_Font* getFontMedium() const { return fontMedium; }
	TTF_Font* getFontLarge() const { return fontLarge; }

private:
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Surface *surfaceWindow;
	TTF_Font *fontSmall;
	TTF_Font *fontMedium;
	TTF_Font *fontLarge;
	Arena *arena;
	Scene *scene;
	int nextSceneId;
	int fps;

	/**
	 * Performs real scene switching.
	 */
	void switchScene();

	static Game *singleton;

public:
	/**
	 * Runs game.
	 */
	void run();
};

#endif // GAME_HXX

