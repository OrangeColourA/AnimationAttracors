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
	void DrawOpenPolyline(std::vector<Vec2D>& model, Color c)
	{
		Vec2D to_center = { float(gfx.ScreenWidth / 2), float(gfx.ScreenHeight / 2) };

		for (auto& verts : model)
		{
			verts.y *= -1.0f;
			verts += to_center;
		}

		gfx.DrawOpenPolyline(model, c);
	}

	void DrawScatterPlot(std::vector<Vec2D>& model, Color c)
	{
		Vec2D to_center = { float(gfx.ScreenWidth / 2 ), float(gfx.ScreenHeight / 2) };

		for (auto& verts : model)
		{
			verts.y *= -10.0f;
			verts += to_center;
		}

		for (auto& verts : model)
		{
			gfx.DrawCircle(verts.get_x(), verts.get_y(), 5, c);
		}
	}

private:
	Graphics& gfx;
};