#pragma once
#include "Vec2D.h"


class Mat3
{
public:
	float m[3][3];

	Mat3(Vec3D row1, Vec3D row2, Vec3D row3)
	{
		m[0][0] = row1.get_x(); m[0][1] = row1.get_y(); m[0][2] = row1.get_z();
		m[1][0] = row2.get_x(); m[1][1] = row2.get_y(); m[1][2] = row2.get_z();
		m[2][0] = row3.get_x(); m[2][1] = row3.get_y(); m[2][2] = row3.get_z();
	}

	Vec3D mult_m3_v3D(Vec3D v)
	{
		return Vec3D(
			m[0][0] * v.get_x() + m[0][1] * v.get_y() + m[0][2] * v.get_z(),
			m[1][0] * v.get_x() + m[1][1] * v.get_y() + m[1][2] * v.get_z(),
			m[2][0] * v.get_x() + m[2][1] * v.get_y() + m[2][2] * v.get_z()
		);

	}

};

class Mat4
{
public:
	float m[4][4];

	Mat4() {
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				m[i][j] = 0.f;
			}
		};
	}

	Mat4 make_proj_matrix(float aspect_ratio, float fov, float z_near, float z_far)
	{
		Mat4 proj;

		float lambda = z_far / (z_far - z_near);

		proj.m[0][0] = aspect_ratio / tanf(0.5f * fov);
		proj.m[1][1] = 1 / tanf(0.5f * fov );
		proj.m[2][2] = lambda;
		proj.m[2][3] = -lambda * z_near;
		proj.m[3][2] = 1.f;

		return proj;
	}

	Mat4 make_transl_matrix(float x, float y, float z)
	{
		Mat4 trans;


		trans.m[0][0] = 1.f;
		trans.m[1][1] = 1.f;
		trans.m[2][2] = 1.f;
		trans.m[3][3] = 1.f;

		trans.m[0][3] = x;
		trans.m[1][3] = x;
		trans.m[2][3] = y;

		return trans;
	}



	Vec4D operator*(Vec4D v)
	{
		return Vec4D(
			m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z + m[0][3] * v.w,
			m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z + m[1][3] * v.w,
			m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z + m[2][3] * v.w,
			m[3][0] * v.x + m[3][1] * v.y + m[3][2] * v.z + m[3][3] * v.w
		);
	}

};