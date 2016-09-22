/**
 * @file scene_lost.hxx
 * @desc Lost scene header.
 */
#ifndef SCENES_SCENE_LOST_HXX
#define SCENES_SCENE_LOST_HXX

/**
 * Lost scene.
 */
class SceneLost : public Scene
{
public:
	virtual ~SceneLost();
	SceneLost();

	virtual void handleActivate(bool active);
	virtual void handleKey(SDL_KeyboardEvent key);
	virtual void render(int timeUsed);

private:
	SDL_Surface *surface;
	SDL_Texture *texture;
};

#endif // SCENES_SCENE_LOST_HXX

