#include "life.h"
#include <gfx_engine/gfxengine.h>
#include <algorithm>

Life::Life(SDL_Rect rect, int cellSize)
	: Widget(rect)
	, _drawGrid(false)
	, _isRun(false)
	, _cellSize(cellSize)
	, _width(_rect.w / cellSize)
	, _height(_rect.h / cellSize)
	, _step(0) {

	_life.resize(_height);
	for (auto& i : _life) {
		i.resize(_width);
		std::fill(i.begin(), i.end(), false);
	}
}

void Life::update() {
	if (_isRun) {
		auto c(_life);

		for (int i = 0; i < _height; ++i) {
			for (int j = 0; j < _width; ++j) {
				int count = 0;
				for (int k = std::max(i - 1, 0); k < i + 2 && k < _height; ++k) {
					for (int l = std::max(j - 1, 0); l < j + 2 && l < _width; ++l) {
						if (!(k == i && l == j)) {
							if (_life[k][l] == true) {
								++count;
							}
						}
					}
				}
				if (_life[i][j]) {
					if (!(count == 2 || count == 3)) {
						c[i][j] = false;
					}
				} else if (count == 3) {
					c[i][j] = true;
				}
			}
		}
		_life = c;
		++_step;
	}
}

void Life::draw(GfxEngine &gfxEngine) const {
	if (_drawGrid) {
		gfxEngine.setColor({100,100,100,255});
		for (int i = 0; i <= _height; ++i) {
			gfxEngine.drawLine(0, i * _cellSize, _width * _cellSize, i * _cellSize, this);
		}

		for (int j = 0; j <= _width; ++j) {
			gfxEngine.drawLine(j * _cellSize, 0, j * _cellSize, _height * _cellSize, this);
		}
	}

	gfxEngine.setColor({100,200,100,255});
	for (int i = 0; i < _height; ++i) {
		for (int j = 0; j < _width; ++j) {
			if (_life[i][j]) {
				int ii = i * _cellSize;
				int jj = j * _cellSize;
				gfxEngine.drawRect(jj, ii, _cellSize, _cellSize, this);
			}
		}
	}
}

void Life::handleEvent(const SDL_Event &event) {
	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
		case SDLK_SPACE :
			reset();
			break;
		case SDLK_g:
			_drawGrid ^= 1;
			break;
		case SDLK_s:
			_isRun ^= 1;
			break;
		case SDLK_c:
			clear();
			break;
		}
	} else if (event.type == SDL_MOUSEBUTTONDOWN) {
		Coord c = getWidgetCoord(Coord(event.button.x, event.button.y));
		int i = c._y * _height / _rect.h;
		int j = c._x * _width / _rect.w;
		if (i < _height && j < _width && i >= 0 && j >= 0) {
			_life[i][j] = true;
		}
	} else if (event.type == SDL_MOUSEMOTION && event.button.button == SDL_BUTTON_LEFT) {
		Coord c = getWidgetCoord(Coord(event.button.x, event.button.y));
		int i = c._y * _height / _rect.h;
		int j = c._x * _width / _rect.w;
		if (i < _height && j < _width && i >= 0 && j >= 0) {
			_life[i][j] = true;
		}
	}
}

std::string Life::getId() const {
	return "life";
}

void Life::clear() {
	for (auto& i : _life) {
		std::fill(i.begin(), i.end(), false);
	}
	_step = 0;
}

void Life::reset() {
	for (auto& i : _life) {
		std::generate(i.begin(), i.end(), []() {
			return rand()%2;
		});
	}
	_step = 0;
}

int Life::getStep() const {
	return _step;
}

int Life::getPopulation() const {
	int count = 0;
	for (const auto& sub : _life) {
		count += std::count(sub.begin(), sub.end(), true);
	}
	return count;
}