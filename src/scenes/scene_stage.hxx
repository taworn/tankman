/**
 * @file scene_stage.hxx
 * @desc Stage scene header.
 */
#ifndef SCENES_SCENE_STAGE_HXX
#define SCENES_SCENE_STAGE_HXX

/**
 * Stage scene.
 */
class SceneStage : public Scene
{
public:
	virtual ~SceneStage();
	SceneStage();

	virtual void handleActivate(bool active);
	virtual void handleKey(SDL_KeyboardEvent key);
	virtual void render(int timeUsed);

private:
	SDL_Surface *surface;
	SDL_Texture *texture;
	int timeTotal;
};

#endif // SCENES_SCENE_STAGE_HXX

