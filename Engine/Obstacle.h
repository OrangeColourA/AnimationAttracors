#pragma once


#include "Board.h"

// placed on a board 
// do not hit a snake or an apple ( easy mode )
//  


class Obstacle
{
private:

	bool initialized = false;

	Location loc;
	static constexpr Color col = Colors::Gray;

public:
	void Init(const Location& l);
	void Draw(Board& brd) const;
	bool hit_obstacle(const Location& l) const;

};