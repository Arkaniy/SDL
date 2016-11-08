#ifndef LIFEINFO_H
#define LIFEINFO_H

#include "gui/widget.h"

class Life;

class LifeInfo : public Widget {
public:
	LifeInfo(Rect rect, const Life& life);

	void update() override;
	void draw(GfxEngine& gfxEngine) const override;
	bool handleEvent(const SDL_Event& event) override;
private:
	const Life& _life;
};

#endif // LIFEINFO_H
