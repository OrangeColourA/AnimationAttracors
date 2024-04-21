#include "GoalSquare.h"

GoalSquare::GoalSquare(int x, int y, Graphics& g):
	x(x),
	y(y),
	gfx(g)
{
}

void GoalSquare::Draw()
{
	gfx.DrawRectangle(x, y, x + width, y + width, c);
}

void GoalSquare::Pulsation()
{
	
	c = { 255, colors[i], colors[i]};
	i = i++ % size;
}

bool GoalSquare::Got_Reached(Player& p)
{
	return (p.Get_X() + p.Get_W() >= x && p.Get_X() <= x + width &&
		p.Get_Y() + p.Get_W() >= y && p.Get_Y() <= y + width);
}

void GoalSquare::Change_location(int x_new, int y_new)
{
	x = x_new;
	y = y_new;
}

