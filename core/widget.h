#ifndef WIDGET_H
#define WIDGET_H

#include <vector>
#include <string>
#include "SDL2/SDL.h"

class GfxEngine;

struct Coord {
	int _x;
	int _y;
	Coord(int x, int y) : _x(x), _y(y) {}
	Coord operator+(const Coord& c) {
		return Coord(_x + c._x, _y + c._y);
	}
	Coord operator-(const Coord& c) {
		return Coord(_x - c._x, _y - c._y);
	}
};


class Widget {
public:
	Widget(const SDL_Rect& rect, Widget *parent = nullptr);
	virtual ~Widget() {}

	virtual void draw(GfxEngine& gfxEngine) const = 0;
	virtual void update() = 0;
	virtual void handleEvent(const SDL_Event& event) = 0;
	virtual std::string getId() const = 0;

	Coord getScreenCoord(Coord coord) const;
	Coord getWidgetCoord(Coord coord) const;
	SDL_Rect getScreenRect() const;

	int getX() const { return _rect.x; }
	int getY() const { return _rect.y; }
	int getW() const { return _rect.w; }
	int getH() const { return _rect.h; }
	const SDL_Rect& getRect() const { return _rect; }

	void setX(int value) { _rect.x = value; }
	void setY(int value) { _rect.y = value; }
	void setW(int value) { _rect.w = value; }
	void setH(int value) { _rect.h = value; }

	bool isVisible() const { return _isVisible; }
	bool isActive() const { return _isActive; }
	bool isEnable() const { return _isEnable; }

	void setVisible(bool value) { _isVisible = value; }
	void setActive(bool value) { _isActive = value; }
	void setEnable(bool value) { _isEnable = value; }

	bool isMouseOver(int x, int y) const;

protected:
	SDL_Rect _rect;
	Widget *_parent;

	bool _isVisible;
	bool _isActive;
	bool _isEnable;
};


class WidgetContainer : public Widget {
public:
	WidgetContainer(const SDL_Rect& rect, Widget *parent = nullptr);
	~WidgetContainer() {}

	void draw(GfxEngine& gfxEngine) const;
	void update();
	void handleEvent(const SDL_Event& event);
	std::string getId() const;

	void addChild(Widget *widget);
	Widget* getById(const std::string& id) const;
private:
	std::vector<Widget*> _childs;
};

#endif // WIDGET_H
