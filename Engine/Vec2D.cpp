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

Vec3D::Vec3D(const Vec3D& v)
	:
	x(v.get_x()),
	y( v.get_y()),
	z(v.get_z())
{
	
}

Vec3D::Vec3D(float x_new, float y_new, float z_new)
	:
	x(x_new),
	y(y_new),
	z(z_new)
{
}

float Vec3D::get_x() const
{
	return x;
}

float Vec3D::get_y() const
{
	return y;
}

float Vec3D::get_z() const
{
	return z;
}

void Vec3D::z_divide()
{
	x /= z;
	y /= z;
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

Vec3D Vec3D::operator+(Vec3D add)
{
	return Vec3D(x + add.get_x(),
		y + add.get_y(),
		z + add.get_z());
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
		break;
	}
}

float Vec3D::operator*(Vec3D mult)
{
	return x * mult.get_x() + y * mult.get_y() + z * mult.get_z();
}

Vec3D Vec3D::operator*(float c)
{
	return Vec3D(c*x,c*y,c*z);
}



// VEC 4 D

Vec4D::Vec4D()
	:
	x(0.f),
	y(0.f),
	z(0.f),
	w(0.f)
{
}

Vec4D::Vec4D(const Vec4D& v)
	:
	x(v.x),
	y(v.y),
	z(v.z),
	w(v.w)
{
}

Vec4D::Vec4D(float x_new, float y_new, float z_new, float w_new)
	:
	x(x_new),
	y(y_new),
	z(z_new),
	w(w_new)
{
}

void Vec4D::w_divide()
{
	if (w != 0.f)
	{
		x /= w;
		y /= w;
		z /= w;
	}
}

float Vec4D::length()
{
	return sqrtf(x*x+y*y+z*z+w*w);
}

Vec4D Vec4D::normalize()
{
	float l = length();
	return Vec4D(x/l, y/ l, z/l, w/l);
}

Vec4D Vec4D::operator-(Vec4D sub)
{
	return Vec4D(x -sub.x, y - sub.y, z - sub.z, w - sub.w);
}

Vec4D Vec4D::operator+(Vec4D add)
{
	return Vec4D(x + add.x, y + add.y, z + add.z, w + add.w);
}

float Vec4D::operator*(Vec4D mult)
{
	return x*mult.x + y * mult.y + z * mult.z + w * mult.w;
}

Vec4D Vec4D::operator*(float c)
{
	return Vec4D(c*x,c*y,c*z,c*w);
}


