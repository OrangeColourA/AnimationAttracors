#include "Player.h"



Player::Player(int x, int y, Graphics& g, MainWindow& w) :
	x(x),
	y(y),
	gfx(g),
	wnd(w)
{
}

void Player::Draw()
{
	gfx.DrawRectangle(x, y, x + width, y + width, c);
}

void Player::Moving()
{
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		y -= dy;
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		x -= dx;
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		y += dy;
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		x += dx;
	}

	if (x <= 0)
	{
		x = 0;
	}
	if (x + width >= gfx.ScreenWidth - 1)
	{
		x = gfx.ScreenWidth - width - 1;
	}
	if (y <= 0)
	{
		y = 0;
	}
	if (y + width >= gfx.ScreenHeight - 1)
	{
		y = gfx.ScreenHeight - width - 1;
	}

}

int Player::Get_X()
{
	return x;
}

int Player::Get_Y()
{
	return y;
}

int Player::Get_W()
{
	return width;
}






