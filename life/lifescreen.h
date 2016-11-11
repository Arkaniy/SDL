#ifndef LIFESCREEN_H
#define LIFESCREEN_H

#include "core/screen.h"
#include "life.h"
#include "lifeinfo.h"

class LifeScreen : public Screen {
public:
	LifeScreen(GfxEngine& gfxEngine);
	~LifeScreen() {}

	void handleEvent(const SDL_Event& event);

private:
	Life _life;
	LifeInfo _lifeInfo;
};

#endif // LIFESCREEN_H
