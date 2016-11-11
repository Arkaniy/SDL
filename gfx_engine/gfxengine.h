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
	void setColor(const SDL_Color& color);
	void draw(SDL_Texture *texture, const SDL_Rect &rect, const Widget *widget);
	void drawRect(int x, int y, int w, int h, const Widget *widget);
	void drawLine(int x1, int y1, int x2, int y2, const Widget *widget);
	void drawText(int x, int y, std::string text, TTF_Font *f, const Widget *widget, bool centered = false);
	void endFrame();

	int getTextSize(const std::string& text, TTF_Font *f) const;

private:
	SDL_Window *_window;
	SDL_Renderer *_renderer;
};

#endif // GFXENGINE_H