#pragma once

#include "Graphics.h"
#include "Location.h"

class Board
{
private:
	
	static constexpr int x_pos = 25;
	static constexpr int y_pos = 25;

	static constexpr int ElementSize = 30;
	Graphics& gfx;

public:

	static constexpr int BoardWidth = 25;
	static constexpr int BoardHeight = 18;

	Board(Graphics& gfx) : gfx(gfx) {}

	void DrawElement(const Location& l, Color c)
	{
		gfx.DrawRectDim(x_pos + l.x * ElementSize + 2,
						y_pos + l.y * ElementSize + 2,
						ElementSize - 2 ,
						ElementSize - 2, c);
	}
	void DrawBorder()
	{
		gfx.DrawRectDim(x_pos - 10, y_pos - 10, 20 + BoardWidth * ElementSize, 10, Color(0,30,180));
		gfx.DrawRectDim(x_pos - 10, y_pos + BoardHeight * ElementSize, 20 + BoardWidth * ElementSize, 10, Color(0, 30, 180));
	
		gfx.DrawRectDim(x_pos - 10, y_pos, 10, BoardHeight * ElementSize, Color(0, 30, 180));
		gfx.DrawRectDim(x_pos + BoardWidth * ElementSize, y_pos, 10, BoardHeight * ElementSize, Color(0, 30, 180));
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