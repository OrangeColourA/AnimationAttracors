#include "Mat4f.h"

Mat4f::Mat4f(const Vec4f& r1, const Vec4f& r2, const Vec4f& r3, const Vec4f& r4)
{
	mat[0] = r1;
	mat[1] = r2;
	mat[2] = r3;
	mat[3] = r4;
}

Mat4f::Mat4f(const Mat4f& m)
	:
	Mat4f(m.mat[0], m.mat[1], m.mat[2], m.mat[3])
{}

Mat4f& Mat4f::operator=(const Mat4f & m)
{
	Mat4f(m);
	return *this;
}
