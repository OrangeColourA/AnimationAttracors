#pragma once




class Vec2f
{
public:

	float x;
	float y;

public:
	Vec2f() = default;
	Vec2f(float x, float y);
	Vec2f(const Vec2f& v);
	Vec2f& operator=(const Vec2f& r);
	Vec2f  operator+(const Vec2f& r) const;
	Vec2f& operator+=(const Vec2f& r);
	Vec2f  operator-(const Vec2f& r) const;
	Vec2f& operator-=(const Vec2f& r);
	Vec2f  operator*(float num) const;
	Vec2f& operator*=(float num);
	float GetLengthSq() const;
	float GetLength() const;
	Vec2f GetNormalized() const;
	Vec2f& Normalized();

};