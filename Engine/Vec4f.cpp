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

Vec4f& Vec4f::operator*(const Mat4f& m)
{
	Vec4f temp(*this);
	this->x = temp * Vec4f(m.mat[0].x, m.mat[1].x, m.mat[2].x, m.mat[3].x);
	this->y = temp * Vec4f(m.mat[0].y, m.mat[1].y, m.mat[2].y, m.mat[3].y);
	this->z = temp * Vec4f(m.mat[0].z, m.mat[1].z, m.mat[2].z, m.mat[3].z);
	this->w = temp * Vec4f(m.mat[0].w, m.mat[1].w, m.mat[2].w, m.mat[3].w);

}

float Vec4f::operator*(const Vec4f& rv)
{
	return x * rv.x + y * rv.y + z * rv.z + w * rv.w;
}

Vec2f Vec4f::to_screen_space(const Mat4f& proj)
{

	Vec4f temp(*this);

	temp = temp * proj;

	temp.x = temp.x / temp.w;
	temp.y = temp.y / temp.w;
	temp.z = temp.z / temp.w;
	temp.w = temp.w / temp.w;

	return Vec2f(temp.x / temp.z * Graphics::ScreenWidth / 2 + Graphics::ScreenWidth,
		temp.y / temp.z * Graphics::ScreenHeight / 2 + Graphics::ScreenHeight);
	

}
