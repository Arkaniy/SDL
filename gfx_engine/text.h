#ifndef TEXT_H
#define TEXT_H

#include "core/widget.h"
#include <SDL2/SDL_ttf.h>

class Text : public Widget {
public:
	Text(const SDL_Rect& rect, Widget *parent, const std::string& text, TTF_Font *font, SDL_Color color, bool isCentered = false);

	void draw(GfxEngine& gfxEngine) const;
	void update();
	void handleEvent(const SDL_Event&);
	std::string getId() const;

	void setText(const std::string& text);
	void setText(int n);
private:
	std::string _text;
	TTF_Font *_font;
	SDL_Color _color;
	bool _isCentered;
};

#endif // TEXT_H
