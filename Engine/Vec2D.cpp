#include "Vec2D.h"
#include <cmath>
Vec2D::Vec2D():
	x(0.0f),
	y(0.0f)
{
}
Vec2D::Vec2D(float x_new, float y_new)
{
	x = x_new;
	y = y_new;
}
Vec2D::Vec2D(std::pair<int, int> p)
{
	x = p.first;
	y = p.second;
}
Vec2D::Vec2D(std::pair<float, float> p)
{
	x = p.first;
	y = p.second;
}

float Vec2D::get_x()
{
	return x;
}

float Vec2D::get_y()
{
	return y;
}

void Vec2D::norm()
{
	float l = length();
	x = x / l;
	y = y / l;
}

float Vec2D::length()
{
	return sqrt(x * x + y * y);
}

void Vec2D::operator+=(Vec2D add)
{
	x = x + add.get_x();
	y = y + add.get_y();
}
