#ifndef PONGINFO_H
#define PONGINFO_H

#include "core/widget.h"
#include "gfx_engine/text.h"

class Pong;

class PongInfo : public Widget {
public:
	PongInfo(const SDL_Rect& rect, const Pong& pong);

	void update() override;
	void draw(GfxEngine& gfxEngine) const override;
	void handleEvent(const SDL_Event& event) override;
	std::string getId() const override;
private:
	const Pong& _pong;

	Text _firstScoreText;
	Text _secondScoreText;
};

#endif // PONGINFO_H
