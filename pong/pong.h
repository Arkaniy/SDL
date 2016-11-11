#ifndef PONG_H
#define PONG_H

#include "core/widget.h"

class Ball : public Widget {
public:
	Ball(const SDL_Rect& rect, Widget *parent = nullptr);

	void update() override;
	void draw(GfxEngine& gfxEngine) const override;
	void handleEvent(const SDL_Event& event) override;
	std::string getId() const override;
private:
	int _speed;
	int dx;
	int dy;
};

class Platform : public Widget {
public:
	Platform(const SDL_Rect& rect, Widget *parent = nullptr);

	void update() override;
	void draw(GfxEngine& gfxEngine) const override;
	void handleEvent(const SDL_Event& event) override;
	std::string getId() const override;
};

class Pong : public WidgetContainer {
public:
	Pong(const SDL_Rect& rect, Widget *parent = nullptr);

	void update() override;
	void draw(GfxEngine& gfxEngine) const override;
	void handleEvent(const SDL_Event& event) override;
	std::string getId() const override;
private:
	Ball _ball;
	Platform _platform1;
	Platform _platform2;
};

#endif // PONG_H
