/**
 * @file scene_title.hxx
 * @desc Title scene header.
 */
#ifndef SCENES_SCENE_TITLE_HXX
#define SCENES_SCENE_TITLE_HXX

/**
 * Title scene.
 */
class SceneTitle : public Scene
{
public:
	virtual ~SceneTitle();
	SceneTitle();

	virtual void handleActivate(bool active);
	virtual void handleKey(SDL_KeyboardEvent key);
	virtual void render();

private:
	SDL_Surface *surfaceTitle;
	SDL_Texture *textureTitle;
	SDL_Surface *surfaceMenu;
	SDL_Texture *textureMenu;
	SDL_Surface *surfaceImage;
	SDL_Texture *textureImage;
	int imageX;
};

#endif // SCENES_SCENE_TITLE_HXX

