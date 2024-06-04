#pragma once
#include "Vec2D.h"


class Entity
{
public:
	Entity( std::vector<Vec2D> m, const Vec2D& pos = {0.0f,0.0f})
		:
		model( std::move(m) ),
		position(pos)
	{}
	const Vec2D& GetPos() const
	{
		return position;
	}
	void SetPos(const Vec2D& newPos)
	{
		position = newPos;
	}
	void TranslateBy(const Vec2D& offset)
	{
		position += offset;
	}
	void ScaleBy(const float scale)
	{
		for (auto& v : model)
		{
			v *= scale;
		}
	}
	std::vector<Vec2D> GetPolyline() const
	{
		auto poly = model;
		for (auto& v : poly)
		{
			v += position;
		}

		return poly;

	}



private:
	std::vector<Vec2D> model;
	Vec2D position = { 0.0f, 0.0f };

};