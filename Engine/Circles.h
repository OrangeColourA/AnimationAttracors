#pragma once
#include "Vec2D.h"
#include "Shape.h"
#include "Graphics.h"



class Circle
{
public:
	Circle(Graphics& g)
		:
		gfx( g ),
		radius(5),
		velocity({ 0.0f,0.0f }),
		acceleration({ 0.0f,0.0f }),
		position({ 0.0f,0.0f }),
		body(Shape::Circle(position, radius))
	{}
	//Circle(Graphics& g)
	//	:
	//	gfx(g),
	//	radius(5),
	//	velocity({ 0.0f,0.0f }),
	//	acceleration({ 0.0f,0.0f }),
	//	position({ 0.0f,0.0f }),
	//	body(Shape::Circle(position, radius))
	//{}

	void Draw()
	{
		const float PI = acos(-1.0f);

		Vec2D to_center_of_screen = { Graphics::ScreenWidth / 2, Graphics::ScreenHeight / 2 };

		for (auto& vertex : body)
		{
			vertex += to_center_of_screen;
			vertex.y *= -1.0f;
		}

		Vec2D moved_pos = position + to_center_of_screen;

		Vec2D temp = { radius * cos(2 * PI * velocity.get_y() / velocity.get_x()),
										radius * sin(2 * PI * velocity.get_y() / velocity.get_x()) };
		Vec2D moved_vel = moved_pos + temp;


		gfx.DrawPolyline(body, { 255, 255, 255 });
		gfx.DrawLine(moved_pos, moved_vel, {255,255,255});

	}

	


private:
	Graphics& gfx;
	int radius;
	Vec2D velocity;
	Vec2D acceleration;
	Vec2D position;
	std::vector<Vec2D> body;

};



class Circles_Scene
{



private:
	std::vector<Circle*> scene;

};