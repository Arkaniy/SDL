#include "pongscreen.h"
#include "cfg.h"
#include "gfx_engine/gfxengine.h"
#include "gfx_engine/resourcecontainer.h"

PongScreen::PongScreen(GfxEngine &gfxEngine)
	: Screen(gfxEngine)
	, _pong(SDL_Rect{0, 30, Cfg::WindowWidth, Cfg::WindowHeight - 30})
	, _pongInfo(SDL_Rect{0, 0, Cfg::WindowWidth, 30}, _pong)
	, _pongWinWidget(SDL_Rect{ _widget.getW() / 2 - 125, 50, 250, 100}, &_widget, _pong) {

	_widget.addChild(&_pong);
	_widget.addChild(&_pongInfo);
	_widget.addChild(&_pongWinWidget);
}

void PongScreen::handleEvent(const SDL_Event &event) {
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_1) {
		_nextScreen = new MenuScreen(_gfxEngine);
	} else {
		_widget.handleEvent(event);
	}
}