#include "Vec2D.h"
#include <cmath>
Vec2D::Vec2D(float x_new, float y_new)
{
	x = x_new;
	y = y_new;
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
