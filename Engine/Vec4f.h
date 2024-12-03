#pragma once
#include "Mat4f.h"
#include "Vec2f.h"

class Vec4f
{
public:
	float x;
	float y;
	float z;
	float w;
public:
	Vec4f() = default;
	Vec4f(float x, float y, float z, float w);
	Vec4f(const Vec4f& v);
	Vec4f& operator=(const Vec4f& v);

	Vec4f& operator*(const Mat4f& m);
	float operator*(const Vec4f& rv);

	Vec2f to_screen_space(const Mat4f& proj);

};