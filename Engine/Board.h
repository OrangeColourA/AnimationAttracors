#pragma once

#include "Graphics.h"
#include "Location.h"
#include <random>

class Board
{
private:
	
	static constexpr int x_pos = 25;
	static constexpr int y_pos = 25;

	static constexpr int ElementSize = 25;
	static constexpr int BoardWidth = 30;
	static constexpr int BoardHeight = 22;
	Graphics& gfx;

public:

	Board(Graphics& gfx) : gfx(gfx) {}
	void DrawElement(const Location& l, Color c) const;
	void DrawBorder() const;
	int GetWidth() const;
	int GetHeight() const;
	bool is_inside_board(const Location& loc);
	Location GenerateLoc(std::mt19937 rnd);
	Location GetLocation_mousePos(const Location& Mouse_Pos) const;
	
};