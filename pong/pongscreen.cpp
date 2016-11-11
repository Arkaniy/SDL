#include "pongscreen.h"
#include "cfg.h"
#include "gfx_engine/gfxengine.h"

PongScreen::PongScreen(GfxEngine &gfxEngine)
	: Screen(gfxEngine)
	, _pong(SDL_Rect{30, 30, Cfg::WindowWidth - 60, Cfg::WindowHeight- 60}) {

	_widget.addChild(&_pong);

}

void PongScreen::handleEvent(const SDL_Event &event) {
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_1) {
		_nextScreen = new MenuScreen(_gfxEngine);
	} else {
		_widget.handleEvent(event);
	}
}
