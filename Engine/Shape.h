#pragma once
#include "Vec2D.h"
#include <cmath>


class Shape
{
public:
	static std::vector<Vec2D> Make(float innerRadius, float outerRadius, int nodes = 5)
	{
		std::vector<Vec2D> star;
		star.reserve(nodes * 2);
		const float dTheta = 2.0f * 3.14159f / float(nodes * 2);

		for (int i = 0; i < nodes * 2; i++)
		{
			const float rad = (i % 2 == 0) ? innerRadius : outerRadius;

			star.emplace_back(
				rad * cos(float(i) * dTheta),
				rad * sin(float(i) * dTheta)
			);
		}

		return star;

	}
	static std::vector<Vec2D> MakePlot(std::vector<float> x, std::vector<float> y)
	{
		std::vector<Vec2D> plot;
		plot.reserve(x.size());

		for (size_t i = 0; i < x.size(); i++)
		{
			plot.emplace_back(x[i], y[i]);
		}
		return plot;
	}
};



