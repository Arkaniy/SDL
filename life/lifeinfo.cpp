#include <sstream>
#include "lifeinfo.h"
#include "gfx_engine/gfxengine.h"
#include "gfx_engine/resourcecontainer.h"
#include "life.h"

LifeInfo::LifeInfo(SDL_Rect rect, const Life &life)
	: Widget(rect)
	, _life(life) {

}

void LifeInfo::update() {

}

void LifeInfo::draw(GfxEngine &gfxEngine) const {
	std::stringstream ss("");
	ss << "Step: " << _life.getStep() << " Population: " << _life.getPopulation();
	gfxEngine.setColor({200,200,100,255});
	gfxEngine.drawText(0,0, ss.str(), ResourceContainer::fontContainer["f"], this, true);
}

void LifeInfo::handleEvent(const SDL_Event&) {

}

std::string LifeInfo::getId() const {
	return "lifeInfo";
}
