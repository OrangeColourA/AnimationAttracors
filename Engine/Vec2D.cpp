#include "Vec2D.h"
#include <cmath>
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
