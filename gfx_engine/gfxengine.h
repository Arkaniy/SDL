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
	void draw(const Widget *widget, SDL_Texture *texture);
	void drawRect(const Widget *widget);
	void drawRect(const Widget *widget, const SDL_Rect &rect);
	void drawLine(const Widget *widget, int x1, int y1, int x2, int y2);
	void drawText(const Widget *widget, std::string text, TTF_Font *f, bool centered = false);
	void endFrame();

	int getTextWidth(const std::string& text, TTF_Font *f) const;
	int getTextHeight(const std::string& text, TTF_Font *f) const;

private:
	SDL_Window *_window;
	SDL_Renderer *_renderer;
};

#endif // GFXENGINE_H