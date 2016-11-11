#ifndef APP_H
#define APP_H

#include <SDL2/SDL.h>
#include "gfx_engine/gfxengine.h"

class App {
public:
	App();
	bool init();
	void run();
	void free();
private:
	GfxEngine _gfxEngine;
};

#endif // APP_H
