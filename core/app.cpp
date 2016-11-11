#include "app.h"
#include "screen.h"

App::App() {

}

bool App::init() {
	if (_gfxEngine.init()) {
		_gfxEngine.loadResources();
		return true;
	}
	return false;
}

void App::run() {
	ScreenManager sm;
	sm.push(new MenuScreen(_gfxEngine));
	sm.process();

}

void App::free() {
	_gfxEngine.free();
}