#include "app.h"
#include "gfxengine.h"
#include <iostream>
#include "imagecontainer.h"
#include "panel.h"
#include "cfg.h"

App::App()
	: _life(100, 75, nullptr)
	, _life2(100, 75, nullptr){
	_blocks.push_back(new Block(0,0,300,150));
	_blocks.push_back(new Block(15,175,300,150));

	_life.setBlock(_blocks[0]);
	//_life2.setBlock(_blocks[1]);
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
				_life.handleEvent(event);
				_life2.handleEvent(event);
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
	//_gfxEngine.draw(ResourceContainer::imageContainer["1"], {0,0,720,480});
	_life.draw(_gfxEngine);
	_life2.draw(_gfxEngine);
	_gfxEngine.endFrame();
}
