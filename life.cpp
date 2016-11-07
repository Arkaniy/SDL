#include "life.h"
#include "panel.h"
#include <gfxengine.h>
#include <algorithm>

Life::Life(int width, int height, Block *block)
	: _block(block)
	, _drawGrid(false)
	, _isRun(false)
	, _width(width)
	, _height(height) {

	setBlock(block);

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
	}
}

void Life::draw(GfxEngine &gfxEngine) const {
	if (_drawGrid) {
		for (int i = 0; i <= _height; ++i) {
			int ii = _block->getScreenY(i * _sizeI);
			gfxEngine.drawLine(_block->getScreenX(0), ii, _block->getScreenX(_width * _sizeJ), ii);
		}

		for (int j = 0; j <= _width; ++j) {
			int jj = _block->getScreenX(j * _sizeJ);
			gfxEngine.drawLine(jj, _block->getScreenY(0), jj, _block->getScreenY(_height * _sizeI));
		}
	}

	for (int i = 0; i < _height; ++i) {
		for (int j = 0; j < _width; ++j) {
			if (_life[i][j]) {
				int ii = _block->getScreenY(i * _sizeI);
				int jj = _block->getScreenX(j * _sizeJ);
				gfxEngine.drawRect(jj, ii, _sizeJ, _sizeI, {255,255,0,255});
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
		int i = _block->getPanelY(event.button.y) * _height / _block->getH();
		int j = _block->getPanelX(event.button.x) * _width / _block->getW();
		if (i < _height && j < _width && i >= 0 && j >= 0) {
			_life[i][j] = true;
		}
	} else if (event.type == SDL_MOUSEMOTION && event.button.button == SDL_BUTTON_LEFT) {
		int i = _block->getPanelY(event.button.y) * _height / _block->getH();
		int j = _block->getPanelX(event.button.x) * _width / _block->getW();
		if (i < _height && j < _width && i >= 0 && j >= 0) {
			_life[i][j] = true;
		}
	}
}

void Life::clear() {
	for (auto& i : _life) {
		std::fill(i.begin(), i.end(), false);
	}
}

void Life::reset() {
	for (auto& i : _life) {
		std::generate(i.begin(), i.end(), []() {
			return rand()%2;
		});
	}
}

void Life::setBlock(Block *block)
{
	_block = block;
	if (block != nullptr) {
		_sizeI = block->getH() / _height;
		_sizeJ = block->getW() / _width;
	}
}
