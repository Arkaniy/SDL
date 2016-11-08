#ifndef GFXENGINE_H
#define GFXENGINE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

class Widget;

class GfxEngine {
public:
	GfxEngine();
	~GfxEngine() {}

	bool init();
	void loadResources();
	void free();

	void startFrame();
	void draw(SDL_Texture *texture, const SDL_Rect &rect, const Widget *widget);
	void drawRect(int x, int y, int w, int h, SDL_Color c, const Widget *widget);
	void drawLine(int x1, int y1, int x2, int y2, const Widget *widget);
	void drawText(int x, int y, std::string text, SDL_Color c, TTF_Font *f, const Widget *widget);
	void endFrame();

private:
	SDL_Window *_window;
	SDL_Renderer *_renderer;
};

#endif // GFXENGINE_H