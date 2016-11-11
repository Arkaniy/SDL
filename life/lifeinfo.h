#ifndef LIFEINFO_H
#define LIFEINFO_H

#include "core/widget.h"

class Life;

class LifeInfo : public Widget {
public:
	LifeInfo(SDL_Rect rect, const Life& life);

	void update() override;
	void draw(GfxEngine& gfxEngine) const override;
	void handleEvent(const SDL_Event& event) override;
	std::string getId() const override;
private:
	const Life& _life;
};

#endif // LIFEINFO_H
