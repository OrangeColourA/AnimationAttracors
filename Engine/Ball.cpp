#include "Ball.h"

Ball::Ball(Graphics& g, const Vec2f& p)
	:
	gfx(g),
	center_pos(p)
{}

void Ball::Draw() const
{
	gfx.DrawRect(center_pos - Vec2f(radius, radius), center_pos + Vec2f(radius, radius), color);
}

void Ball::Move(float dt)
{
	center_pos += velocity * dt;
}

bool Ball::Do_wall_collide(const Rectangle_f& wall)
{
	Rectangle_f rect = Rectangle_f::GetRect(center_pos - Vec2f(radius, radius), center_pos + Vec2f(radius, radius));
	bool colided = false;

	if (rect.left < wall.left)
	{
		Bounce_x();
		center_pos.x += wall.left - rect.left;
		
		colided = true;
	}
	else if (rect.right > wall.right)
	{
		Bounce_x();
		center_pos.x -= rect.right - wall.right;
		
		colided = true;
	}

	if (rect.top < wall.top)
	{
		Bounce_y();
		center_pos.y += wall.top - rect.top;
		
		colided = true;
	}
	else if (rect.bottom > wall.bottom)
	{
		Bounce_y();
		center_pos.y -= rect.bottom - wall.bottom;
		//center_pos.y = wall.bottom - 1.f;
		colided = true;
	}

	return colided;
}

void Ball::Bounce_x()
{
	velocity.x = -velocity.x;
}

void Ball::Bounce_y()
{
	velocity.y = -velocity.y;
}
