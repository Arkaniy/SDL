#include "lifescreen.h"
#include "gfx_engine/gfxengine.h"
#include "gfx_engine/resourcecontainer.h"
#include "cfg.h"

LifeScreen::LifeScreen(GfxEngine &gfxEngine)
	: Screen(gfxEngine)
	, _life({ 0, 0, Cfg::WindowWidth, Cfg::WindowHeight - 30}, 6)
	, _lifeInfo({ 0, Cfg::WindowHeight - 30, Cfg::WindowWidth, 30}, _life) {

	_widget.addChild(&_life);
	_widget.addChild(&_lifeInfo);
}

void LifeScreen::handleEvent(const SDL_Event &event) {
	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
		case SDLK_1:
			_nextScreen = new MenuScreen(_gfxEngine);
			break;
		case SDLK_h:
			_widget.getById("life")->setVisible(_widget.getById("life")->isVisible() ^ 1);
			break;
		default:
			_widget.handleEvent(event);
		}
	} else {
		_widget.handleEvent(event);
	}
}