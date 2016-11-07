#ifndef PANEL_H
#define PANEL_H

#include <vector>

class GfxEngine;

class Block {
public:
	Block(int x, int y, int w, int h, Block *parent = nullptr);
	int getScreenX(int value) const;
	int getScreenY(int value) const;
	int getPanelX(int value) const;
	int getPanelY(int value) const;

	int getW() const;
	int getH() const;
private:
	int _x;
	int _y;
	int _w;
	int _h;

	Block *_parent;
};

#endif // PANEL_H
