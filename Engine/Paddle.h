#pragma once

#include "Graphics.h"
#include "Rectangle_f.h"
#include "MainWindow.h"

class Paddle
{
private:
	Vec2f center_pos;
	static constexpr float speed = 4.f * 60.f;
	//Rectangle_f body;
	static constexpr int width = 150;
	static constexpr int heigth = 30;
	static constexpr Color color = Colors::LightGray;
	Graphics& gfx;
public:
	Paddle(Graphics& g, const Vec2f& pos);
	void Move(const Keyboard& kbd, float dt);
	bool Do_wall_collide(const Rectangle_f& walls);
	void Draw() const;
	Rectangle_f GetRect() const;
};