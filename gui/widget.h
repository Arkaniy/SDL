#ifndef WIDGET_H
#define WIDGET_H

#include <vector>

class GfxEngine;
union SDL_Event;

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

struct Rect {
	Coord _coord;
	int _w;
	int _h;
	Rect(Coord coord, int w, int h) : _coord(coord), _w(w), _h(h) {}
};

class Widget {
public:
	Widget(const Rect& rect, Widget *parent = nullptr);
	virtual ~Widget() {}

	virtual void draw(GfxEngine& gfxEngine) const;
	virtual void update();
	virtual bool handleEvent(const SDL_Event& event);

	void addChild(Widget *widget);
	Coord getScreenCoord(Coord coord) const;
	Coord getWidgetCoord(Coord coord) const;

	int getW() const;
	int getH() const;

protected:
	Rect _rect;

	Widget *_parent;
	std::vector<Widget*> _childs;
};

#endif // WIDGET_H
