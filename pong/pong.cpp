#include "pong.h"
#include "gfx_engine/gfxengine.h"
#include "gfx_engine/resourcecontainer.h"

Pong::Pong(const SDL_Rect &rect, Widget *parent)
	: WidgetContainer(rect, parent)
	, _ball(SDL_Rect{ 500, 300, 25, 25 }, this)
	, _platform1(SDL_Rect{ 50,300, 10, 75 }, this)
	, _platform2(SDL_Rect{ _rect.w - 60, 0, 10, 75 }, this)
	, _firstScore(0)
	, _secondScore(0) {

	addChild(&_ball);
	addChild(&_platform1);
	addChild(&_platform2);

}

void Pong::update() {
	if (isIntersect(_ball, _platform1)) {
		_ball.changeDirection(_platform1.getRect());
	}
	if (isIntersect(_ball, _platform2)) {
		_ball.changeDirection(_platform2.getRect());
	}

	if (_ball.wasOut() == -1) {
		++_secondScore;
	} else if (_ball.wasOut() == 1) {
		++_firstScore;
	}

	_ball.resetWasOut();
	WidgetContainer::update();
}

void Pong::draw(GfxEngine &gfxEngine) const {
	//gfxEngine.draw(this, ResourceContainer::imageContainer["play"]);
	WidgetContainer::draw(gfxEngine);
}

void Pong::handleEvent(const SDL_Event &event) {
	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
		case SDLK_w:
			_platform1.move(-1);
			break;
		case SDLK_s:
			_platform1.move(1);
			break;
		case SDLK_UP:
			_platform2.move(-1);
			break;
		case SDLK_DOWN:
			_platform2.move(1);
			break;
		default:
			break;
		}
	}

	WidgetContainer::handleEvent(event);
}

std::string Pong::getId() const {
	return "pong";
}

bool Pong::isIntersect(const Widget &w1, const Widget &w2) const {
	return SDL_HasIntersection(&w1.getRect(), &w2.getRect());
}

void Pong::reset() {
	_platform1.setY(300);
	_platform2.setY(300);

	_firstScore = 0;
	_secondScore = 0;
}

Ball::Ball(const SDL_Rect &rect, Widget *parent)
	: Widget(rect, parent)
	, _speed(6)
	, _dx(_speed)
	, _dy(_speed)
	, _wasOut(0) {

}

void Ball::update() {
	if (getX() + getW() + _dx >= _parent->getW()) {
		_wasOut = 1;
		_dx = -_speed;
	} else if (getX() + _dx < 0) {
		_wasOut = -1;
		_dx = _speed;
	}

	if (getY() + getH() + _dy >= _parent->getH()) {
		_dy = -_speed;
	} else if (getY() + _dy < 0) {
		_dy = _speed;
	}

	setX(getX() + _dx);
	setY(getY() + _dy);
}

void Ball::draw(GfxEngine &gfxEngine) const {
	gfxEngine.draw(this, ResourceContainer::imageContainer["ball"]);
}

void Ball::handleEvent(const SDL_Event &event) {

}

std::string Ball::getId() const {
	return "ball";
}

void Ball::changeDirection(const SDL_Rect &rect) {
	if (getX() - _dx >= rect.x + rect.w || getX() + getW() - _dx <= rect.x) {
		_dx = -_dx;
	}
	if (getY() - _dy >= rect.y + rect.h || getY() + getH() - _dy <= rect.y) {
		_dy = -_dy;
	}
}


Platform::Platform(const SDL_Rect &rect, Widget *parent)
	: Widget(rect, parent)
	, _speed(4) {

}

void Platform::update() {

}

void Platform::draw(GfxEngine &gfxEngine) const {
	gfxEngine.setColor({200,200,0,255});
	gfxEngine.drawRect(this);
}

void Platform::handleEvent(const SDL_Event &event) {

}

std::string Platform::getId() const {
	return "platform";
}

void Platform::move(int dy) {
	setY(getY() + dy * _speed);
}
