#pragma once


class Vec2D
{
private:
	float x;
	float y;

public:
	Vec2D(float x_new, float y_new);
	float get_x();
	float get_y();
	void norm();
	float length();

};