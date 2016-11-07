#include <iostream>
#include <SDL2/SDL_image.h>
#include "gfxengine.h"
#include "resourceloader.h"
#include "cfg.h"

GfxEngine::GfxEngine()
	: _window(nullptr)
	, _renderer(nullptr) {

}

bool GfxEngine::init() {
	if(SDL_Init(SDL_INIT_VIDEO) == 0) {
		_window = SDL_CreateWindow("My window", 300, 50, Cfg::WindowWidth, Cfg::WindowHeight, SDL_WINDOW_SHOWN);
		if (_window != nullptr) {
			_renderer = SDL_CreateRenderer(_window, 0, SDL_RENDERER_ACCELERATED/* | SDL_RENDERER_PRESENTVSYNC*/);
			if (_renderer == nullptr) {
				std::cout << "Cannot create renderer\n";
				return false;
			}
			if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
				std::cout<<"Cannot init img\n";
				return false;
			}
		} else {
			std::cout << "Cannot create window\n";
			return false;
		}
	} else {
		std::cout << "Cannot init sdl\n";
		return false;
	}
	return true;
}

void GfxEngine::loadResources() {
	ResourceLoader resourceLoader(_renderer);

	resourceLoader.loadImage("1.jpg", "1");
}

void GfxEngine::free() {
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);

	IMG_Quit();
	SDL_Quit();
}

void GfxEngine::startFrame() {
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 0);
	SDL_RenderClear(_renderer);
}

void GfxEngine::draw(SDL_Texture *texture, const SDL_Rect &rect) {
	SDL_RenderCopy(_renderer, texture , nullptr, &rect);
}

void GfxEngine::drawRect(int x, int y, int w, int h, SDL_Color c) {
	SDL_SetRenderDrawColor(_renderer, c.r,c.g,c.b,c.a);
	SDL_Rect r { x, y, w, h};
	SDL_RenderFillRect(_renderer, &r);
}

void GfxEngine::drawLine(int x1, int y1, int x2, int y2) {
	SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
	SDL_RenderDrawLine(_renderer, x1, y1, x2, y2);
}

void GfxEngine::endFrame() {
	SDL_RenderPresent(_renderer);
}