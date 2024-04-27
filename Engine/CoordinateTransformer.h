#pragma once
#include "Graphics.h"
#include "Vec2D.h"

class CoordinateTransformer
{
public:
	CoordinateTransformer(Graphics& g)
		:
		gfx( g )
	{}

	void DrawPolyline(std::vector<Vec2D>& model, Color c)
	{
		Vec2D to_center = { float(gfx.ScreenWidth / 2), float(gfx.ScreenHeight / 2) };

		for (auto& verts : model)
		{
			verts.y *= -1.0f;
			verts += to_center;
		}
		
		gfx.DrawPolyline(model, c);
	}

private:
	Graphics& gfx;
};