#pragma once


class Vec4f;
class Mat4f;
class Vec2f;




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
	Vec2f Normalized();

};

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
	Vec4f& operator= (const Vec4f& r);
	Vec4f  operator+ (const Vec4f& r) const;
	Vec4f& operator+=(const Vec4f& r);
	Vec4f  operator- (const Vec4f& r) const;
	Vec4f& operator-=(const Vec4f& r);
	Vec4f  operator*(float num) const;
	Vec4f& operator*=(float num);
	float GetLengthSq() const;
	float GetLength() const;
	Vec4f GetNormalized() const;
	Vec4f Normalized();

	operator Vec2f() const;
};

class Mat4f
{
public:
	float els[4][4];


public:
	Vec4f operator*(const Vec4f& rv) const;

	static Mat4f make_view_transformation(int ScrWidth, int ScrHeight);

	static Mat4f make_rotation_y(float angle);

	static Mat4f make_rotation_z(float angle);

};