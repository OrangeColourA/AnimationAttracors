#include "Brick.h"

Brick::Brick(int x, int y, Color c)
	:
	body(static_cast<float>(x), static_cast<float>(x + width), static_cast<float>(y), static_cast<float>(y + heigth)),
	color(c)
{}

void Brick::Init(int x, int y, Color c)
{
	body = Rectangle_f::GetRect( Vec2f(static_cast<float>(x),		  static_cast<float>(y)		    ),
								 Vec2f(static_cast<float>(x + width), static_cast<float>(y + heigth)) );
	color = c;
	initialized = true;
}

void Brick::Draw(Graphics& g) const
{

	if (initialized && !destroyed)
	{
		g.DrawRect(Vec2f(body.left, body.top) + Vec2f(2.f,2.f),
			Vec2f(body.right, body.bottom) - Vec2f(2.f, 2.f),	color);
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

int Brick::GetWidth() 
{
	return width;
}

int Brick::GetHeight() 
{
	return heigth;
}

Vec2f Brick::GetCenter() const
{
	return Vec2f((body.right - body.left) / 2, (body.top - body.bottom) / 2);
}
