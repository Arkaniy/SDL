#include <sstream>
#include "lifeinfo.h"
#include "gfx_engine/gfxengine.h"
#include "gfx_engine/resourcecontainer.h"
#include "life.h"

LifeInfo::LifeInfo(SDL_Rect rect, const Life &life)
	: Widget(rect)
	, _life(life)
	, _text(rect, this, "", ResourceContainer::fontContainer["f"], SDL_Color{200,200,0,255}, true) {

}

void LifeInfo::update() {
	std::stringstream ss("");
	ss << "Step: " << _life.getStep() << " Population: " << _life.getPopulation();
	_text.setText(ss.str());
}

void LifeInfo::draw(GfxEngine &gfxEngine) const {
	gfxEngine.draw(this, ResourceContainer::imageContainer["play"]);
	_text.draw(gfxEngine);
}

void LifeInfo::handleEvent(const SDL_Event&) {

}

std::string LifeInfo::getId() const {
	return "lifeInfo";
}
