#pragma once
#include "Graphics.h"


class Mat4f
{
public:
	static constexpr short SIZE = 4;
	Vec4f mat[SIZE];

public:
	Mat4f() = default;
	Mat4f(const Vec4f& r1, const Vec4f& r2, const Vec4f& r3, const Vec4f& r4);
	Mat4f(const Mat4f& m);
	Mat4f& operator=(const Mat4f& m);
	static Mat4f make_proj_matrix();

};