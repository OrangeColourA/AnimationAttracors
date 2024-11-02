#pragma once

#include "Graphics.h"
#include "Location.h"

class Board
{
private:
	static constexpr int BoardWidth  = 25;
	static constexpr int BoardHeight = 18;
	static constexpr int ElementSize = 30;
	Graphics& gfx;

public:

	Board(Graphics& gfx) : gfx(gfx) {}

	void DrawElement(const Location& l, Color c)
	{
		gfx.DrawRectDim(l.x * ElementSize, l.y * ElementSize, ElementSize, ElementSize, c);
	}

	int GetWidth()
	{
		return BoardWidth;
	}

	int GetHeight()
	{
		return BoardHeight;
	}

};