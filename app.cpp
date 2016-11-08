#include "app.h"
#include "gfxengine.h"
#include <iostream>
#include "imagecontainer.h"
#include "cfg.h"

App::App()
	: _life(Rect(Coord(10, 0), 300, 150), 5)
	, _life2(Rect(Coord(10, 175), 300, 150), 10)
	, _lifeInfo(Rect(Coord(20, 400), 50, 25), _life) {

}

bool App::init() {
	if (_gfxEngine.init()) {
		_gfxEngine.loadResources();
		return true;
	}
	return false;
}

void App::run() {
	SDL_Event event;
	bool isRun = true;

	while (isRun) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				isRun = false;
			} else {
				if (!_life.handleEvent(event)) {
					_life2.handleEvent(event);
				}
			}
		}

		update();
		draw();

		//SDL_Delay(80);
	}
}

void App::free() {
	_gfxEngine.free();
}

void App::update() {
	_life.update();
	_life2.update();
}

void App::draw() {
	_gfxEngine.startFrame();
	_life.draw(_gfxEngine);
	_life2.draw(_gfxEngine);
	_lifeInfo.draw(_gfxEngine);
	_gfxEngine.endFrame();
}
