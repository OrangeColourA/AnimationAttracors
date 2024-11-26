#include "Vec4f.h"

Vec4f::Vec4f(float x, float y, float z, float w)
	:
	x(x), y(y), z(z), w(w)
{}

Vec4f::Vec4f(const Vec4f & v)
	:
	Vec4f(v.x,v.y,v.z,v.w)
{}

Vec4f& Vec4f::operator=(const Vec4f & v)
{
	Vec4f(v);
	return *this;
}
