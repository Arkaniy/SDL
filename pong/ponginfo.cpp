#include "gfx_engine/resourcecontainer.h"
#include "gfx_engine/gfxengine.h"
#include "ponginfo.h"
#include "pong.h"

PongInfo::PongInfo(const SDL_Rect &rect, const Pong &pong)
	: Widget(rect)
	, _pong(pong)
	, _firstScoreText(SDL_Rect {getW() / 4, 0, 0, 30}, this, "0", ResourceContainer::fontContainer["f"], SDL_Color{255,255,255,255}, true)
	, _secondScoreText(SDL_Rect {getW() / 4 * 3, 0, 0, 30}, this, "0", ResourceContainer::fontContainer["f"], SDL_Color{255,255,255,255}, true) {

}

void PongInfo::update() {
	_firstScoreText.setText(_pong.getFirstScore());
	_secondScoreText.setText(_pong.getSecondScore());
}

void PongInfo::draw(GfxEngine &gfxEngine) const {
	gfxEngine.draw(this, ResourceContainer::imageContainer["panel"]);
	_firstScoreText.draw(gfxEngine);
	_secondScoreText.draw(gfxEngine);

	gfxEngine.setColor({255,255,255,255});
	gfxEngine.drawText(this, "PONG PLAY", ResourceContainer::fontContainer["f"], true);
}

void PongInfo::handleEvent(const SDL_Event &event) {

}

std::string PongInfo::getId() const {
	return "pongInfo";
}
