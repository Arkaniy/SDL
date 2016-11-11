#ifndef LIFE_H
#define LIFE_H

#include <vector>
#include <core/widget.h>

class Life : public Widget {
public:
	Life(SDL_Rect rect, int cellSize);

	void update() override;
	void draw(GfxEngine& gfxEngine) const override;
	void handleEvent(const SDL_Event& event) override;
	std::string getId() const;

	void clear();
	void reset();

	int getStep() const;
	int getPopulation() const;

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
