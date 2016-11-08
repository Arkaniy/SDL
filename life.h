#ifndef LIFE_H
#define LIFE_H

#include <vector>
#include <gui/widget.h>

class GfxEngine;
union SDL_Event;
class Block;

class Life : public Widget {
public:
	Life(Rect rect, int cellSize);

	void update() override;
	void draw(GfxEngine& gfxEngine) const override;
	bool handleEvent(const SDL_Event& event) override;

	void clear();
	void reset();

	int getStep() const;

private:
	std::vector<std::vector<bool>> _life;

	bool _drawGrid;
	bool _isRun;

	int _cellSize;
	int _width;
	int _height;

	int _step;
};

#endif // LIFE_H
