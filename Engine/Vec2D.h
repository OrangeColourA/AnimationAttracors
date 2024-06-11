#pragma once
#include <vector>

class Vec2D
{
public:
	float x;
	float y;

public:
	Vec2D();
	Vec2D(float x_new, float y_new);
	Vec2D(std::pair<int, int> p);
	Vec2D(std::pair<float, float> p);
	float get_x();
	float get_y();
	void norm();
	float length();
	void operator+=( Vec2D ) ;
	void operator-=(Vec2D);
	void operator*=(float);
	Vec2D operator+(Vec2D);

};