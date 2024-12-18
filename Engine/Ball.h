#pragma once

#include "Rectangle_f.h"
#include "Graphics.h"
#include "Brick.h"
#include "Paddle.h"

class Ball
{

private:
	Vec2f center_pos;
	Vec2f velocity = Vec2f(6.f * 60.f,-6.f * 60.f);
	const Vec2f initial_velocity = Vec2f(6.f * 60.f, -6.f * 60.f);
	static constexpr float dv = 360.f;
	static constexpr float radius = 7.f;
	Color color = Colors::Cyan;
	Graphics& gfx;
	
public:

	Ball(Graphics& g, const Vec2f& p);

	void Draw() const;
	void Move(float dt);

	bool Do_wall_collide(const Rectangle_f& wall, bool& game_over);

	bool Detect_brick_collioson(Brick& br);
	void Handle_brick_collision(Brick& br);
	void ResetPos(const Rectangle_f& walls);
	
	bool Hit_paddle(Paddle& pad);
	//bool do_brick_collide(???)
	void Bounce_x();
	void Bounce_y();
	void Bounce_y_paddle(const Vec2f& center_pad, int width_pad);
	Vec2f Get_pos() const;

};