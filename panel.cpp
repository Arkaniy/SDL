#include "panel.h"

Block::Block(int x, int y, int w, int h, Block *parent)
	: _x(x)
	, _y(y)
	, _w(w)
	, _h(h)
	, _parent(parent) {
}

int Block::getScreenX(int value) const {
	if (value > _x + _w) {
		value = _x + _w;
	}

	if (_parent != nullptr) {
		return _parent->getScreenX(value + _x);
	} else {
		return value + _x;
	}
}

int Block::getScreenY(int value) const {
	if (value > _y + _h) {
		value = _y + _h;
	}

	if (_parent != nullptr) {
		return _parent->getScreenY(value + _y);
	} else {
		return value + _y;
	}
}

int Block::getPanelX(int value) const {
	if (_parent != nullptr) {
		return _parent->getScreenY(value - _x);
	} else {
		return value - _x;
	}
}

int Block::getPanelY(int value) const {
	if (_parent != nullptr) {
		return _parent->getScreenY(value - _y);
	} else {
		return value - _y;
	}
}

int Block::getW() const {
	return _w;
}

int Block::getH() const {
	return _h;
}
