#include "GameMathLib.h"

#include <cmath>





// Vec2f implementation
/***********************************************************************************
************************************************************************************
***********************************************************************************/

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

	return *this * (1.f / GetLength());
}

Vec2f Vec2f::Normalized()
{
	return this->GetNormalized();
}

/***********************************************************************************
************************************************************************************
***********************************************************************************/





// Vec4f implementation
/***********************************************************************************
************************************************************************************
***********************************************************************************/
Vec4f::Vec4f(float x, float y, float z, float w)
	:
	x(x),
	y(y),
	z(z),
	w(w)
{
}

Vec4f::Vec4f(const Vec4f& v)
	:
	Vec4f(v.x, v.y, v.z, v.w)
{
}

Vec4f& Vec4f::operator=(const Vec4f& r)
{
	x = r.x;
	y = r.y;
	z = r.z;
	w = r.w;
	return *this;
}

Vec4f Vec4f::operator+(const Vec4f& r) const
{
	return Vec4f(x + r.x, y + r.y, z + r.z, w + r.w);
}

Vec4f& Vec4f::operator+=(const Vec4f& r)
{
	return *this = *this + r;
}

Vec4f Vec4f::operator-(const Vec4f& r) const
{
	return Vec4f(x - r.x, y - r.y, z - r.z, w - r.w);
}

Vec4f& Vec4f::operator-=(const Vec4f& r)
{
	return *this = *this - r;
}

Vec4f Vec4f::operator*(float num) const
{
	return Vec4f(x * num, y * num, z * num, w * num);
}

Vec4f& Vec4f::operator*=(float num)
{
	return *this = *this * num;
}

float Vec4f::GetLengthSq() const
{
	return x * x + y * y + z * z + w * w;
}

float Vec4f::GetLength() const
{
	return std::sqrt(this->GetLengthSq());
}

Vec4f Vec4f::GetNormalized() const
{
	float len = GetLength();

	if (len == 0.0f)
	{
		return *this;
	}

	return *this * (1.f / GetLength());
}

Vec4f Vec4f::Normalized()
{
	return this->GetNormalized();
}

Vec4f::operator Vec2f() const
{
	return Vec2f(x, y);
}

/***********************************************************************************
************************************************************************************
***********************************************************************************/



Vec4f Mat4f::operator*(const Vec4f& rv) const
{
	Vec4f vout;

	vout.x = els[0][0] * rv.x + els[0][1] * rv.y + els[0][2] * rv.z + els[0][3] * rv.w;
	vout.y = els[1][0] * rv.x + els[1][1] * rv.y + els[1][2] * rv.z + els[1][3] * rv.w;
	vout.z = els[2][0] * rv.x + els[2][1] * rv.y + els[2][2] * rv.z + els[2][3] * rv.w;
	vout.w = els[3][0] * rv.x + els[3][1] * rv.y + els[3][2] * rv.z + els[3][3] * rv.w;

	return vout;
}

Mat4f Mat4f::make_view_transformation(int ScrWidth, int ScrHeight)
{
	return {
		ScrWidth / 2.f,    0.f            ,  0.f, (ScrWidth - 1.f) / 2.f ,
		0.f           ,    ScrHeight / 2.f,  0.f, (ScrHeight - 1.f) / 2.f,
		0.f			  ,	   0.f			  ,  1.f,		0.f				 ,
		0.f			  ,	   0.f			  ,  0.f,		1.f
	};
}

Mat4f Mat4f::make_rotation_y(float angle)
{
	return {
		cosf(angle)   ,    0.f            ,  sinf(angle),       0.f		   	,
		0.f           ,    1.f            ,  0.f		,		0.f         ,
		-sinf(angle)  ,	   0.f			  ,  cosf(angle),		0.f			,
		0.f			  ,	   0.f			  ,  0.f		,		1.f
	};
}

Mat4f Mat4f::make_rotation_z(float angle)
{
	return {
		cosf(angle)   ,    -sinf(angle)   ,  0.f ,       0.f	  	,
		sinf(angle)   ,    cosf(angle)    ,  0.f ,		 0.f        ,
		0.f           ,	   0.f			  ,  1.f ,		 0.f		,
		0.f			  ,	   0.f			  ,  0.f ,		 1.f
	};
}

