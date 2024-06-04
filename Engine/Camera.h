#pragma once

#include "CoordinateTransformer.h"

class Camera
{
public:
	Camera(CoordinateTransformer& ct)
		:
		ct(ct)
	{}

	Vec2D GetPos()
	{
		return pos;
	}

	void MoveBy(const Vec2D& offset)
	{
		pos += offset;
	}

	void MoveTo(const Vec2D& pos_in)
	{
		pos = pos_in;
	}

	float GetScale()
	{
		return scale;
	}

	void SetScale(float s)
	{
		scale = s;
	}

	void DrawOpenPolyline(std::vector<Vec2D>& model, Color c)
	{

		for (auto& verts : model)
		{
			verts -= pos;
			verts *= scale;
		}

		ct.DrawOpenPolyline( std::move( model ), c );

	}

	void DrawScatterPlot( std::vector<Vec2D>& model, Color c )
	{
		//Vec2D to_center = { float(gfx.ScreenWidth / 2), float(gfx.ScreenHeight / 2) };

		for (auto& verts : model)
		{

			verts -= pos;
			verts *= scale;

		}

		ct.DrawScatterPlot( model, c );

	}

private:
	Vec2D pos = { 0.0f, 0.0f };
	float scale = 1.0f;
	CoordinateTransformer& ct;
};