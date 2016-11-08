#include "widget.h"

Widget::Widget(const Rect &rect, Widget *parent)
	: _rect(rect)
	, _parent(parent) {

}

void Widget::draw(GfxEngine &gfxEngine) const {
	for (const auto& child : _childs) {
		child->draw(gfxEngine);
	}
}

void Widget::update() {
	for (auto& child : _childs) {
		child->update();
	}
}

bool Widget::handleEvent(const SDL_Event &event) {
	for (auto& child : _childs) {
		if (child->handleEvent(event)) {
			return true;
		}
	}
	return false;
}

void Widget::addChild(Widget *widget) {
	_childs.push_back(widget);
}

Coord Widget::getScreenCoord(Coord coord) const {
	if (coord._x > _rect._coord._x + _rect._w) {
		coord._x = _rect._coord._x + _rect._w;
	}

	if (coord._y > _rect._coord._y + _rect._h) {
		coord._y = _rect._coord._y + _rect._h;
	}

	if (_parent != nullptr) {
		return _parent->getScreenCoord(coord + _rect._coord);
	} else {
		return coord + _rect._coord;
	}
}

Coord Widget::getWidgetCoord(Coord coord) const {
	if (_parent != nullptr) {
		return _parent->getScreenCoord(coord - _rect._coord);
	} else {
		return coord - _rect._coord;
	}
}

int Widget::getW() const {
	return _rect._w;
}

int Widget::getH() const {
	return _rect._h;
}
