#pragma once



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


};