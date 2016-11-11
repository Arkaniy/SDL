#include "pong.h"
#include "gfx_engine/gfxengine.h"
#include "gfx_engine/resourcecontainer.h"

Pong::Pong(const SDL_Rect &rect, Widget *parent)
	: WidgetContainer(rect, parent)
	, _ball(SDL_Rect{ 500, 300, 25, 25 }, this)
	, _platform1(SDL_Rect{ 50,0, 10, 75 }, this)
	, _platform2(SDL_Rect{ _rect.w - 60, 0, 10, 75 }, this) {

	addChild(&_ball);
	addChild(&_platform1);
	addChild(&_platform2);
}

void Pong::update() {
	WidgetContainer::update();
}

void Pong::draw(GfxEngine &gfxEngine) const {
	gfxEngine.draw(ResourceContainer::imageContainer["play"], {0, 0, _rect.w, _rect.h}, this);

	gfxEngine.setColor({255,255,255,255});
	gfxEngine.drawText(0, 0, "PONG PLAY", ResourceContainer::fontContainer["f"], this, true);

	WidgetContainer::draw(gfxEngine);
}

void Pong::handleEvent(const SDL_Event &event) {

}

std::string Pong::getId() const {
	return "pong";
}

Ball::Ball(const SDL_Rect &rect, Widget *parent)
	: Widget(rect, parent)
	, _speed(10)
	, dx(_speed)
	, dy(_speed) {

}

void Ball::update() {
	if (getX() + dx >= _parent->getW()) {
		dx = -_speed;
	} else if (getX() + dx < 0) {
		dx = _speed;
	}

	if (getY() + dy >= _parent->getH()) {
		dy = -_speed;
	} else if (getY() + dy < 0) {
		dy = _speed;
	}

	setX(getX() + dx);
	setY(getY() + dy);
}

void Ball::draw(GfxEngine &gfxEngine) const {
	gfxEngine.setColor({200,0,0,255});
	gfxEngine.drawRect(0, 0, 25, 25, this);
}

void Ball::handleEvent(const SDL_Event &event) {

}

std::string Ball::getId() const {
	return "ball";
}


Platform::Platform(const SDL_Rect &rect, Widget *parent)
	: Widget(rect, parent) {

}

void Platform::update() {

}

void Platform::draw(GfxEngine &gfxEngine) const {
	gfxEngine.setColor({200,200,0,255});
	gfxEngine.drawRect(0, 0,10 , 75, this);
}

void Platform::handleEvent(const SDL_Event &event) {

}

std::string Platform::getId() const {
	return "platform";
}
