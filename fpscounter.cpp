#include "fpscounter.h"
#include "gfx_engine/gfxengine.h"
#include "gfx_engine/resourcecontainer.h"
#include <sstream>

FpsCounter::FpsCounter(const SDL_Rect &rect, Widget *parent)
	: Widget(rect, parent)
	, _currentFps(0)
	, _currentFrame(0) {

}

void FpsCounter::draw(GfxEngine &gfxEngine) const {
	std::stringstream ss;
	ss << _currentFps;
	gfxEngine.setColor({255,255,255,255});
	gfxEngine.drawText(this, ss.str(), ResourceContainer::fontContainer["f"]);
}

void FpsCounter::update() {
	static Uint32 start = SDL_GetTicks();
	_currentFrame++;
	Uint32 end = SDL_GetTicks();
	if (end - start >= 1000) {
		_currentFps = _currentFrame;
		_currentFrame = 0;
		start = end;
	}
}

void FpsCounter::handleEvent(const SDL_Event&) {

}

std::string FpsCounter::getId() const {
	return "fpsCounter";
}
