#include "widget.h"
#include <algorithm>

Widget::Widget(const SDL_Rect &rect, Widget *parent)
	: _rect(rect)
	, _parent(parent)
	, _isVisible(true)
	, _isActive(true)
	, _isEnable(true) {

}

Coord Widget::getScreenCoord(Coord coord) const {
	if (coord._x > _rect.x + _rect.w) {
		coord._x = _rect.x + _rect.w;
	} else if (coord._x < 0) {
		coord._x = 0;
	}

	if (coord._y > _rect.y + _rect.h) {
		coord._y = _rect.y + _rect.h;
	} else if (coord._y < 0) {
		coord._y = 0;
	}

	if (_parent != nullptr) {
		return _parent->getScreenCoord(coord + Coord(_rect.x, _rect.y));
	} else {
		return coord + Coord(_rect.x, _rect.y);
	}
}

Coord Widget::getWidgetCoord(Coord coord) const {
	if (_parent != nullptr) {
		return _parent->getWidgetCoord(coord - Coord(_rect.x, _rect.y));
	} else {
		return coord - Coord(_rect.x, _rect.y);
	}
}

WidgetContainer::WidgetContainer(const SDL_Rect &rect, Widget *parent)
	: Widget(rect, parent) {

}

void WidgetContainer::draw(GfxEngine &gfxEngine) const {
	for (const auto& child : _childs) {
		if (child->isVisible()) {
			child->draw(gfxEngine);
		}
	}
}

void WidgetContainer::update() {
	for (auto& child : _childs) {
		if (child->isActive()) {
			child->update();
		}
	}
}

void WidgetContainer::handleEvent(const SDL_Event &event) {
	for (auto& child : _childs) {
		if (child->isEnable()) {
			child->handleEvent(event);
		}
	}
}

std::string WidgetContainer::getId() const {
	return "container";
}

void WidgetContainer::addChild(Widget *widget) {
	_childs.push_back(widget);
}

Widget *WidgetContainer::getById(const std::string &id) const {
	return *std::find_if(_childs.begin(), _childs.end(), [&id](auto& child) {
		return id == child->getId();
	});
}
