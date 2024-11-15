#include "Brick.h"

Brick::Brick(Graphics& g, int x, int y, Color c)
	:
	gfx(g),
	body(static_cast<float>(x), static_cast<float>(x + width), static_cast<float>(y), static_cast<float>(y + heigth)),
	color(c)
{}

void Brick::Draw()
{
	//if (!destroyed)
	//{
		gfx.DrawRect_f(body, color);
	//}
}

void Brick::Destroy()
{
	destroyed = true;
}

Rectangle_f Brick::GetRect()
{
	return body;
}
