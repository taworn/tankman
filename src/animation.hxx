/**
 * @file animation.hxx
 * @desc Animation header.
 */
#ifndef ANIMATION_HXX
#define ANIMATION_HXX

class Sprite;

/**
 * An animation class.
 */
class Animation
{
public:
	static const int ON_END_CONTINUE = 0;
	static const int ON_END_KEEP_LAST_FRAME = 1;
	static const int ON_END_HIDDEN = 2;

	/**
	 * Destructs an animation.
	 */
	~Animation();

	/**
	 * Constructs an animation.
	 */
	Animation();

	/**
	 * Adds a playing animation, only 16 set allow.
	 */
	void add(int number, int start, int end, int onEnd, int time);

	/**
	 * Uses a playing animation.
	 */
	void use(int number);

	/**
	 * Draws animation.
	 */
	void draw(SDL_Renderer *renderer, Sprite *sprite, SDL_Rect *rectTarget);

	float getCurrentX() const { return currentX; }
	float getCurrentY() const { return currentY; }
	float getVelocityX() const { return velocityX; }
	float getVelocityY() const { return velocityY; }

	void moveTo(float x, float y)
	{
		currentX = x;
		currentY = y;
	}

	void moveBy(float dx, float dy)
	{
		currentX += dx;
		currentY += dy;
	}

	void setVelocity(float dx, float dy)
	{
		velocityX = dx;
		velocityY = dy;
	}

	void playFrame(bool enableX, bool enableY)
	{
		if (enableX)
			currentX += velocityX;
		if (enableY)
			currentY += velocityY;
	}

	bool isEnded() const { return ending; }

private:
	static const int PLAYING_MAX = 16;
	struct PLAYING {
		int start;
		int end;
		int onEnd;
		unsigned int time;
	};
	PLAYING plays[PLAYING_MAX];
	int currentPlaying;
	int currentImage;
	bool ending;

	float currentX, currentY;
	float velocityX, velocityY;

	unsigned int timeStart;

	Animation(const Animation&);
	Animation& operator=(const Animation&);
};

#endif // ANIMATION_HXX

