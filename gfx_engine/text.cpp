#include "text.h"
#include "gfxengine.h"
#include <sstream>

Text::Text(const SDL_Rect& rect, Widget *parent, const std::string &text, TTF_Font *font, SDL_Color color, bool isCentered)
	: Widget(rect, parent)
	, _text(text)
	, _font(font)
	, _color(color)
	, _isCentered(isCentered) {

}

void Text::draw(GfxEngine &gfxEngine) const {
	gfxEngine.setColor(_color);
	gfxEngine.drawText(this, _text, _font,_isCentered);
}

void Text::update() {

}

void Text::handleEvent(const SDL_Event&) {

}

std::string Text::getId() const {
	return "text";
}

void Text::setText(const std::string &text) {
	_text = text;
}

void Text::setText(int n)
{
	std::stringstream ss;
	ss << n;
	_text = ss.str();
}
