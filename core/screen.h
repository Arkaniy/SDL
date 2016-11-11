#ifndef SCREEN_H
#define SCREEN_H

#include <stack>
#include "widget.h"

class Screen {
public:
	Screen(GfxEngine& gfxEngine);
	virtual ~Screen() {}

	virtual void draw() const;
	virtual void update();
	virtual void handleEvent(const SDL_Event& event);

	Screen* run();
protected:
	GfxEngine& _gfxEngine;
	WidgetContainer _widget;
	Screen *_nextScreen;
};


class MenuScreen : public Screen {
public:
	MenuScreen(GfxEngine& gfxEngine);
	~MenuScreen() {}

	void draw() const;
	void update();
	void handleEvent(const SDL_Event& event);
};


class ScreenManager {
public:
	void push(Screen *screen);
	void pop();
	void process();
private:
	std::stack<Screen*> _screens;
};

#endif // SCREEN_H
