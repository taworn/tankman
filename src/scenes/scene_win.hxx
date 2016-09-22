/**
 * @file scene_win.hxx
 * @desc Win scene header.
 */
#ifndef SCENES_SCENE_WIN_HXX
#define SCENES_SCENE_WIN_HXX

/**
 * Win scene.
 */
class SceneWin : public Scene
{
public:
	virtual ~SceneWin();
	SceneWin();

	virtual void handleActivate(bool active);
	virtual void handleKey(SDL_KeyboardEvent key);
	virtual void render();

private:
};

#endif // SCENES_SCENE_WIN_HXX

