#include "Brick.h"

Brick::Brick(Graphics& g, int x, int y, Color c)
	:
	gfx(g),
	body(static_cast<float>(x), static_cast<float>(x + width), static_cast<float>(y), static_cast<float>(y + heigth)),
	color(c)
{}

void Brick::Draw()
{
	if (!destroyed)
	{
		gfx.DrawRect_f(body, color);
	}
}

void Brick::Destroy()
{
	destroyed = true;
}

bool Brick::is_destroyed() const
{
	return destroyed;
}

Rectangle_f Brick::GetRect() const
{
	return body;
}
