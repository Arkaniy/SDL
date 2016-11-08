#include <sstream>
#include "lifeinfo.h"
#include "gfxengine.h"
#include "imagecontainer.h"
#include "life.h"

LifeInfo::LifeInfo(Rect rect, const Life &life)
	: Widget(rect)
	, _life(life) {

}

void LifeInfo::update() {

}

void LifeInfo::draw(GfxEngine &gfxEngine) const {
	std::stringstream ss("");
	ss << _life.getStep();
	gfxEngine.draw(ResourceContainer::imageContainer["1"], {0, 0, _rect._w,_rect._h}, this);
	gfxEngine.drawText(0,0, ss.str(), {0,255,0,255}, ResourceContainer::fontContainer["f"], this);

}

bool LifeInfo::handleEvent(const SDL_Event &event) {
	return false;
}
