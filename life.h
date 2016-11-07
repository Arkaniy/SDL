#ifndef LIFE_H
#define LIFE_H

#include <vector>

class GfxEngine;
union SDL_Event;
class Block;

class Life {
public:
	Life(int width, int height, Block *block);

	void update();
	void draw(GfxEngine& gfxEngine) const;
	void handleEvent(const SDL_Event& event);
	void clear();
	void reset();

	void setBlock(Block *block);
private:
	std::vector<std::vector<bool>> _life;
	Block *_block;

	bool _drawGrid;
	bool _isRun;

	int _width;
	int _height;
	int _sizeI;
	int _sizeJ;
};

#endif // LIFE_H
