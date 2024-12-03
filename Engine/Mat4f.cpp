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

Mat4f Mat4f::make_proj_matrix()
{

	const float PI = 3.139;
	const float fov = PI / 2;

	const float aspect = static_cast<float>(Graphics::ScreenHeight) /
		static_cast<float>(Graphics::ScreenWidth);

	const float h = cosf(fov) / sinf(fov);
	const float w = aspect * h;

	const float z_far = 200.f;
	const float z_near = 10.f;

	const float q = z_far / (z_far - z_near);

	return Mat4f(Vec4f(w,     0.f,       0.f,		   0.f),
			     Vec4f(0.f,    h,        0.f,		   0.f),
			     Vec4f(0.f,    q,        0.f,		   1.f),
			     Vec4f(0.f,    0.f,   -q * z_near,	   0.f)
	);





}
