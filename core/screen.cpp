#include "SDL2/SDL.h"
#include "screen.h"
#include "cfg.h"
#include "life/lifescreen.h"
#include "pong/pongscreen.h"
#include "gfx_engine/gfxengine.h"
#include "gfx_engine/resourcecontainer.h"
#include "fpscounter.h"

Screen::Screen(GfxEngine &gfxEngine)
	: _gfxEngine(gfxEngine)
	, _widget(SDL_Rect{0, 0, Cfg::WindowWidth, Cfg::WindowHeight})
	, _nextScreen(nullptr) {

}

void Screen::draw() const {
	_widget.draw(_gfxEngine);
}

void Screen::update() {
	_widget.update();
}

void Screen::handleEvent(const SDL_Event &event) {

}

Screen *Screen::run() {
	SDL_Event event;
	FpsCounter fpsCounter(SDL_Rect{0,0,50,25});

	int frameRate = 60;
	int frameMs = 1000 / frameRate;

	while (_nextScreen == nullptr) {
		int startMs = SDL_GetTicks(); //when the frame starts
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				return _nextScreen;
			} else {
				handleEvent(event);
			}
		}

		fpsCounter.update();
		update();

		_gfxEngine.startFrame();
		draw();
		fpsCounter.draw(_gfxEngine);
		_gfxEngine.endFrame();


		int endMs = SDL_GetTicks(); //when the frame calculations end
		int delayMs = frameMs - (endMs - startMs); //how long to delay
		//SDL_Delay(delayMs); //delay processing
	}
	return _nextScreen;
}


void ScreenManager::push(Screen *screen) {
	_screens.push(screen);
}

void ScreenManager::process() {
	while (!_screens.empty()) {
		Screen *next = _screens.top()->run();
		delete _screens.top();
		_screens.pop();
		if (next != nullptr) {
			_screens.push(next);
		}
	}
}


MenuScreen::MenuScreen(GfxEngine &gfxEngine)
	: Screen(gfxEngine) {

}

void MenuScreen::draw() const {
	_gfxEngine.draw(ResourceContainer::imageContainer["menu"], {0,0,720,480}, &_widget);
}

void MenuScreen::update() {

}

void MenuScreen::handleEvent(const SDL_Event &event) {
	if (event.type == SDL_KEYDOWN) {
		switch(event.key.keysym.sym) {
		case SDLK_1 :
			_nextScreen = new LifeScreen(_gfxEngine);
			break;
		case SDLK_2 :
			_nextScreen = new PongScreen(_gfxEngine);
			break;
		}
	}
}