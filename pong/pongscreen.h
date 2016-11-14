#ifndef PONGSCREEN_H
#define PONGSCREEN_H

#include "core/screen.h"
#include "pong.h"
#include "ponginfo.h"
#include "pongwinwidget.h"

class PongScreen : public Screen {
public:
	PongScreen(GfxEngine& gfxEngine);
	~PongScreen() {}

	void handleEvent(const SDL_Event& event);

private:
	Pong _pong;
	PongInfo _pongInfo;
	PongWinWidget _pongWinWidget;
};

#endif // PONGSCREEN_H
