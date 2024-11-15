#pragma once


#include "Vec2f.h"



class Rectangle_f
{
public:
	float left;
	float right;
	float top;
	float bottom;
public:

	Rectangle_f() = default;
	Rectangle_f(float l, float r, float t, float b);
	Rectangle_f(const Vec2f& top_left, const Vec2f& bottom_right);
	Rectangle_f(const Vec2f& top_left, float width, float height);

	bool is_intersect(const Rectangle_f& rect);

	static Rectangle_f GetRect(const Vec2f& top_left, const Vec2f& bottom_right);

};