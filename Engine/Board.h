#pragma once

#include "Graphics.h"
#include "Location.h"
#include <random>

class Board
{
private:
	
	static constexpr int x_pos = 25;
	static constexpr int y_pos = 25;

	static constexpr int ElementSize = 30;
	static constexpr int BoardWidth = 25;
	static constexpr int BoardHeight = 18;
	Graphics& gfx;

public:

	Board(Graphics& gfx) : gfx(gfx) {}
	void DrawElement(const Location& l, Color c) const;
	void DrawBorder() const;
	int GetWidth() const;
	int GetHeight() const;
	bool is_inside_board(const Location& loc);
	Location GenerateLoc(std::mt19937 rnd)
	{
		std::uniform_int_distribution<int> pos_x(5, BoardWidth - 5);
		std::uniform_int_distribution<int> pos_y(5, BoardHeight - 5);

		return { pos_x(rnd), pos_y(rnd) };
	}
};