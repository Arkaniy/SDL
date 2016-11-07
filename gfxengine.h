#ifndef GFXENGINE_H
#define GFXENGINE_H

#include <SDL2/SDL.h>

class GfxEngine {
public:
	GfxEngine();
	~GfxEngine() {}

	bool init();
	void loadResources();
	void free();

	void startFrame();
	void draw(SDL_Texture *texture, const SDL_Rect& rect);
	void drawRect(int x, int y, int w, int h, SDL_Color c);
	void drawLine(int x1, int y1, int x2, int y2);
	void endFrame();

private:
	SDL_Window *_window;
	SDL_Renderer *_renderer;
};

#endif // GFXENGINE_H