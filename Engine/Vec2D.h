#pragma once


class Vec2D
{
private:
	float x;
	float y;

public:
	float get_x();
	float get_y();
	void norm();
	float length();
};