#pragma once
#include "Vec2D.h"
#include "Colors.h";

class Material
{
public:
	Color diffuse_color;

	Material(Color& c) : diffuse_color(c) {}
	Material() : diffuse_color() {}

};


class Sphere
{
public:
	Vec3D center;
	float radius;
	Material material;

	Sphere(Vec3D&c, const float &r, Material m)
		:
		center(c),
		radius(r),
		material(m)
	{}

	bool ray_intersect(
		Vec3D & orig,
		Vec3D & dir,
		float & t0
	) 
	{
		//Vec3D c = center;
		Vec3D L = center - orig;
		float d_center_proj = L * dir;
		float d_center_ray = L * L - d_center_proj * d_center_proj;
		
		if (d_center_ray > radius * radius)
		{
			return false;
		}

		float dif = sqrtf(radius * radius - d_center_ray);

		t0 = d_center_proj - dif;
		float t1 = d_center_proj + dif;

		if (t0 < 0)
		{
			t0 = t1;
		}

		if (t0 < 0)
		{
			return false;
		}

		return true;

	}
};