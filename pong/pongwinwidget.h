#ifndef PONGWINWIDGET_H
#define PONGWINWIDGET_H

#include "core/widget.h"
#include "gfx_engine/text.h"

class Pong;

class PongWinWidget : public Widget {
public:
	PongWinWidget(const SDL_Rect& rect, Widget *parent, Pong& pong);

	void update() override;
	void draw(GfxEngine& gfxEngine) const override;
	void handleEvent(const SDL_Event& event) override;
	std::string getId() const override;
private:
	Pong& _pong;
};

#endif // PONGWINWIDGET_H
