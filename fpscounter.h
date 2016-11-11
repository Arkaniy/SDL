#ifndef FPSCOUNTER_H
#define FPSCOUNTER_H

#include "core/widget.h"

class FpsCounter : public Widget {
public:
	FpsCounter(const SDL_Rect& rect, Widget *parent = nullptr);

	void draw(GfxEngine& gfxEngine) const;
	void update();
	void handleEvent(const SDL_Event& event);
	std::string getId() const;
private:
	int _currentFps;
	int _currentFrame;
};

#endif // FPSCOUNTER_H
