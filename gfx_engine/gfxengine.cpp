#include <iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "gfxengine.h"
#include "resourceloader.h"
#include "resourcecontainer.h"
#include "cfg.h"
#include "core/widget.h"

GfxEngine::GfxEngine()
	: _window(nullptr)
	, _renderer(nullptr) {

}

bool GfxEngine::init() {
	if(SDL_Init(SDL_INIT_VIDEO) == 0) {
		_window = SDL_CreateWindow("My window", 300, 50, Cfg::WindowWidth, Cfg::WindowHeight, SDL_WINDOW_SHOWN);
		if (_window != nullptr) {
			_renderer = SDL_CreateRenderer(_window, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (_renderer == nullptr) {
				std::cout << "Cannot create renderer\n";
				return false;
			}
			if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
				std::cout<<"Cannot init img\n";
				return false;
			}
			if (TTF_Init() < 0) {
				std::cout << "Cannot init font\n";
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

	resourceLoader.loadImage("1.jpg", "play");
	resourceLoader.loadImage("2.jpg", "menu");
	resourceLoader.loadFont("f.ttf", "f");
}

void GfxEngine::free() {
	for (auto& image: ResourceContainer::imageContainer) {
		SDL_DestroyTexture(image.second);
	}

	for (auto& font: ResourceContainer::fontContainer) {
		TTF_CloseFont(font.second);
	}

	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);

	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}

void GfxEngine::startFrame() {
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 0);
	SDL_RenderClear(_renderer);
}

void GfxEngine::setColor(const SDL_Color &color) {
	SDL_SetRenderDrawColor(_renderer, color.r, color.g, color.b, color.a);
}

void GfxEngine::draw(SDL_Texture *texture, const SDL_Rect &rect, const Widget *widget) {
	SDL_Rect r = rect;
	Coord c = widget->getScreenCoord(Coord(rect.x, rect.y));
	r.x = c._x;
	r.y = c._y;
	SDL_RenderCopy(_renderer, texture , nullptr, &r);
}

void GfxEngine::drawRect(int x, int y, int w, int h, const Widget *widget) {
	SDL_Rect r { x, y, w, h};

	r.x = widget->getScreenCoord(Coord(x,y))._x;
	r.y = widget->getScreenCoord(Coord(x,y))._y;

	SDL_RenderFillRect(_renderer, &r);
}

void GfxEngine::drawLine(int x1, int y1, int x2, int y2, const Widget *widget) {
	Coord c1 = widget->getScreenCoord(Coord(x1,y1));
	Coord c2 = widget->getScreenCoord(Coord(x2,y2));

	x1 = c1._x;
	y1 = c1._y;
	x2 = c2._x;
	y2 = c2._y;

	SDL_RenderDrawLine(_renderer, x1, y1, x2, y2);
}

void GfxEngine::drawText(int x, int y, std::string text, TTF_Font *f, const Widget *widget, bool centered) {
	SDL_Color c;
	SDL_GetRenderDrawColor(_renderer, &c.r,&c.g,&c.b,&c.a);
	SDL_Surface *loadedSurface = TTF_RenderText_Solid(f, text.c_str(), c);
	if (loadedSurface == NULL) {
		return;
	}
	SDL_Texture *texture = SDL_CreateTextureFromSurface(_renderer, loadedSurface);
	if (texture == nullptr) {
		SDL_FreeSurface(loadedSurface);
		return;
	}

	if (centered) {
		x = widget->getX() + (widget->getW() - getTextSize(text, f)) / 2;
	}

	draw(texture, SDL_Rect{x, y, loadedSurface->w, loadedSurface->h}, widget);
	SDL_FreeSurface(loadedSurface);
	SDL_DestroyTexture(texture);

}

void GfxEngine::endFrame() {
	SDL_RenderPresent(_renderer);
}

int GfxEngine::getTextSize(const std::string &text, TTF_Font *f) const {
	int w = 0;
	TTF_SizeText(f, text.c_str(), &w, nullptr);
	return w;
}