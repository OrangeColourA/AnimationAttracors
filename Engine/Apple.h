#pragma once

#include "Snake.h"


class Apple
{
private:
	Location loc = { 1,1 };
	Board& brd;
	std::mt19937 rng;
	

public:

	Apple(Board& brd) : brd(brd) {}

	void Set()
	{
		std::uniform_int_distribution<int> pos_x(0, brd.GetWidth() - 3);
		std::uniform_int_distribution<int> pos_y(0, brd.GetHeight() - 3);

		loc.x = pos_x(rng);
		loc.y = pos_y(rng);
	}

	Location GetLoc()
	{
		return loc;
	}

	void Draw()
	{
		brd.DrawElement(loc, Colors::Red);
	}
};