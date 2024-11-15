#pragma once

#include "Rectangle_f.h"
#include "Graphics.h"
#include "Brick.h"


class Ball
{

private:
	Vec2f center_pos;
	Vec2f velocity = Vec2f(3.f * 60.f,3.f * 60.f);
	static constexpr float radius = 7.f;
	Color color = Colors::Cyan;
	Graphics& gfx;
	
public:

	Ball(Graphics& g, const Vec2f& p);

	void Draw() const;
	void Move(float dt);

	bool Do_wall_collide(const Rectangle_f& wall);
	bool Hit_brick(const Rectangle_f& brick);
	//bool do_brick_collide(???)
	void Bounce_x();
	void Bounce_y();

};