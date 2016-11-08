#ifndef APP_H
#define APP_H

#include <SDL2/SDL.h>
#include "gfxengine.h"
#include "life.h"
#include "lifeinfo.h"

class App {
public:
	App();
	bool init();
	void run();
	void free();
private:
	void update();
	void draw();

	std::vector<Block*> _blocks;

	Life _life;
	Life _life2;
	LifeInfo _lifeInfo;

	GfxEngine _gfxEngine;
};

#endif // APP_H
