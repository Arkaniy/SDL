#include "pongwinwidget.h"
#include "gfx_engine/gfxengine.h"
#include "gfx_engine/resourcecontainer.h"
#include "pong.h"

PongWinWidget::PongWinWidget(const SDL_Rect &rect, Widget *parent, Pong& pong)
	: Widget(rect, parent)
	, _pong(pong) {

	setVisible(false);
}

void PongWinWidget::update() {
	if (_pong.getFirstScore() == 3) {
		_pong.setEnable(false);
		_pong.setActive(false);
		setVisible(true);
	}
	if (_pong.getSecondScore() == 3) {
		_pong.setEnable(false);
		_pong.setActive(false);
		setVisible(true);
	}
}

void PongWinWidget::draw(GfxEngine &gfxEngine) const {
	gfxEngine.draw(this, ResourceContainer::imageContainer["play"]);
}

void PongWinWidget::handleEvent(const SDL_Event &event) {
	if (event.type == SDL_MOUSEBUTTONDOWN && isMouseOver(event.button.x, event.button.y)) {
		setVisible(false);
		_pong.setEnable(true);
		_pong.setActive(true);
		_pong.reset();
	}
}

std::string PongWinWidget::getId() const {

}
