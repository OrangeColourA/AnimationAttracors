#include "Obstacle.h"

void Obstacle::Init(const Location& l)
{
	if (!initialized)
	{
		initialized = true;
		loc = l;
	}
}

void Obstacle::Draw(Board& brd) const
{
	if (initialized)
	{
		brd.DrawElement(loc, col);
	}
}

bool Obstacle::hit_obstacle(const Location& l) const
{
	return l.x == loc.x && l.y == loc.y;
}
