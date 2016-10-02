/**
 * @file bullet.hxx
 * @desc Bullet header.
 */
#ifndef GAME_BULLET_HXX
#define GAME_BULLET_HXX

/**
 * A bullet class.
 */
class Bullet
{
public:
	/**
	 * Destructor.
	 */
	~Bullet();

	/**
	 * Constructor.
	 */
	Bullet(int x, int y, int dir);

	/**
	 * Plays animation.
	 */
	void play(int timeUsed);

	/**
	 * Draws bullet.
	 */
	void draw(SDL_Renderer *renderer, Sprite *spriteMisc, SDL_Rect *viewport, int timeUsed);

private:
	SDL_Point point;
	int direction;
	int imageIndex;

	Bullet(const Bullet&);
	Bullet& operator=(const Bullet&);
};

#endif // GAME_BULLET_HXX

