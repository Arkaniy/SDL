#ifndef PONG_H
#define PONG_H

#include "core/widget.h"
#include "gfx_engine/text.h"

class Ball : public Widget {
public:
	Ball(const SDL_Rect& rect, Widget *parent = nullptr);

	void update() override;
	void draw(GfxEngine& gfxEngine) const override;
	void handleEvent(const SDL_Event& event) override;
	std::string getId() const override;

	void changeDirection(const SDL_Rect& rect);
	int wasOut() const { return _wasOut; }
	void resetWasOut() { _wasOut = 0; }

private:
	int _speed;
	int _dx;
	int _dy;
	int _wasOut;
};

class Platform : public Widget {
public:
	Platform(const SDL_Rect& rect, Widget *parent = nullptr);

	void update() override;
	void draw(GfxEngine& gfxEngine) const override;
	void handleEvent(const SDL_Event& event) override;
	std::string getId() const override;

	void move(int dy);
private:
	int _speed;
};

class Pong : public WidgetContainer {
public:
	Pong(const SDL_Rect& rect, Widget *parent = nullptr);

	void update() override;
	void draw(GfxEngine& gfxEngine) const override;
	void handleEvent(const SDL_Event& event) override;
	std::string getId() const override;

	bool isIntersect(const Widget& w1, const Widget& w2) const;
	int getFirstScore() const { return _firstScore; }
	int getSecondScore() const { return _secondScore; }
	void reset();
private:
	Ball _ball;
	Platform _platform1;
	Platform _platform2;

	int _firstScore;
	int _secondScore;


};

#endif // PONG_H
