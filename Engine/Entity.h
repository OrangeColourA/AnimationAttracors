#pragma once
#include "Vec2D.h"


class Entity
{
public:
	Entity( std::vector<Vec2D> m)
		:
		model( std::move(m) )
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