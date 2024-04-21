#include "Enemy.h"

Enemy::Enemy(int x, int y, int d, Graphics& g)
	:
	x(x),
	y(y),
	direction(d),
	gfx(g)
{
	direction %= 4;
	if (direction == 1)
	{
		dx = -dx;
	}
	else if (direction == 2)
	{
		dx = -dx;
		dy = -dy;
	}
	else if (direction == 3)
	{
		dy = -dy;
	}
}

void Enemy::Moving()
{
	x += dx;
	y += dy;

	if (x < 2)
	{
		dx = -dx;
	}
	if (x + width >= gfx.ScreenWidth - 2)
	{
		dx = -dx;
	}
	if (y < 2)
	{
		dy = -dy;
	}
	if (y + width >= gfx.ScreenHeight - 2)
	{
		dy = -dy;
	}
}

void Enemy::Draw()
{
	gfx.DrawRectangle(x, y, x + width, y + width, c);
}

bool Enemy::Player_Hited(Player& p)
{
	return (p.Get_X() + p.Get_W() >= x && p.Get_X() <= x + width &&
		p.Get_Y() + p.Get_W() >= y && p.Get_Y() <= y + width);
}
