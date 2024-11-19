#include "Paddle.h"

Paddle::Paddle(Graphics& g, const Vec2f& pos)
	:
	gfx(g),
	center_pos(pos)
{}

void Paddle::Move(const Keyboard& kbd, float dt)
{
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		center_pos.x -= speed * dt;
	}

	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		center_pos.x += speed * dt;
	}
}

bool Paddle::Do_wall_collide(const Rectangle_f& walls)
{

	Rectangle_f pad = GetRect();

	if (pad.left < walls.left)
	{
		center_pos.x = width / 2 + 1.f;
		return true;
	}

	if (pad.right > walls.right)
	{
		center_pos.x = walls.right - width / 2;
		return true;
	}


	return false;
}

void Paddle::Draw() const
{
	Vec2f v(width / 2, heigth / 2);
	gfx.DrawRect(center_pos - v, center_pos + v, color);
}

Rectangle_f Paddle::GetRect() const
{
	Vec2f v(width / 2, heigth / 2);
	return Rectangle_f(center_pos - v, center_pos + v);
}

int Paddle::GetWidth() const
{
	return width;
}

void Paddle::ResetCooldown()
{
	isOnCooldown = false;
}

void Paddle::SetOnCooldown()
{
	isOnCooldown = true;
}

bool Paddle::isCooldown() const
{
	return isOnCooldown;
}
