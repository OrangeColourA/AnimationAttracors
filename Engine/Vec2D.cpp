#include "Vec2D.h"
#include <cmath>
Vec2D::Vec2D():
	x(0.0f),
	y(0.0f)
{
}
Vec2D::Vec2D(float x_new, float y_new)
{
	x = x_new;
	y = y_new;
}
Vec2D::Vec2D(std::pair<int, int> p)
{
	x = static_cast<float>(p.first);
	y = static_cast<float>(p.second);
}
Vec2D::Vec2D(std::pair<float, float> p)
{
	x = p.first;
	y = p.second;
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

void Vec2D::operator+=(Vec2D add)
{
	x += add.get_x();
	y += add.get_y();
}

void Vec2D::operator-=(Vec2D add)
{
	x -= add.get_x();
	y -= add.get_y();
}

void Vec2D::operator*=(float f)
{
	x *= f;
	y *= f;
}

Vec2D Vec2D::operator+(Vec2D add)
{
	x += add.get_x();
	y += add.get_y();

	return Vec2D(x, y);
}


// VEC 3D

Vec3D::Vec3D() : x(0.0f), y(0.0f), z(0.0f)
{
}

Vec3D::Vec3D(Vec3D& v)
{
	x = v.get_x();
	y = v.get_y();
	z = v.get_z();
}

Vec3D::Vec3D(float x_new, float y_new, float z_new)
	:
	x(x_new),
	y(y_new),
	z(z_new)
{
}

float Vec3D::get_x()
{
	return x;
}

float Vec3D::get_y()
{
	return y;
}

float Vec3D::get_z()
{
	return z;
}

float Vec3D::length()
{
	return sqrtf(x*x + y*y +z*z);
}

Vec3D Vec3D::normalize()
{
	float l = length();
	return Vec3D(
		x / l,
		y / l,
		z / l);
}


Vec3D Vec3D::operator-(Vec3D sub)
{

	return Vec3D(x - sub.get_x(),
		y - sub.get_y(),
		z - sub.get_z());

}

float& Vec3D::operator[](int n)
{
	switch (n)
	{
	case 0:
		return x;
		break;
	case 1:
		return y;
		break;
	case 2:
		return z;
		//break;
	//deafult:
	}
}

float Vec3D::operator*(Vec3D mult)
{
	return x * mult.get_x() + y * mult.get_y() + z * mult.get_z();
}
