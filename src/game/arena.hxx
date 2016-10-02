/**
 * @file arena.hxx
 * @desc Battle area header.
 */
#ifndef GAME_ARENA_HXX
#define GAME_ARENA_HXX

/**
 * A battle area.
 */
class Arena
{
public:
	/**
	 * Destructs the arena.
	 */
	virtual ~Arena();

	/**
	 * Constructs the arena.
	 */
	Arena();

	/**
	 * Gets score.
	 */
	int getScore() const { return score; }

	/**
	 * Gets stage.
	 */
	int getStage() const { return stage; }

	/**
	 * Starts batlle.
	 */
	void startBattle();

	/**
	 * Draws a battle scene.
	 */
	void draw(int timeUsed);

	Map* getMap() { return map; }

private:
	int score;
	int stage;
	Map *map;

	Arena(const Arena&);
	Arena& operator=(const Arena&);
};

#endif // GAME_ARENA_HXX

