#include "Vec2f.h"
#include <cmath>


Vec2f::Vec2f(float x, float y)
	:
	x(x),
	y(y)
{
}

Vec2f::Vec2f(const Vec2f& v)
	:
	Vec2f(v.x, v.y)
{
}

Vec2f& Vec2f::operator=(const Vec2f& r)
{
	x = r.x;
	y = r.y;
	return *this;
}

Vec2f Vec2f::operator+(const Vec2f& r) const
{
	return Vec2f(x + r.x, y + r.y);
}

Vec2f& Vec2f::operator+=(const Vec2f& r)
{
	return *this = *this + r;
}

Vec2f Vec2f::operator-(const Vec2f& r) const
{
	return Vec2f(x - r.x, y - r.y);
}

Vec2f& Vec2f::operator-=(const Vec2f& r)
{
	return *this = *this - r;
}

Vec2f Vec2f::operator*(float num) const
{
	return Vec2f(x * num, y * num);
}

Vec2f& Vec2f::operator*=(float num)
{
	return *this = *this * num;
}

float Vec2f::GetLengthSq() const
{
	return x * x + y * y;
}

float Vec2f::GetLength() const
{
	return std::sqrt(this->GetLengthSq());
}

Vec2f Vec2f::GetNormalized() const
{
	float len = GetLength();

	if (len == 0.0f)
	{
		return *this;
	}

	return *this * (1.f / GetLength() );
}

Vec2f& Vec2f::Normalized()
{
	return this->GetNormalized();
}
