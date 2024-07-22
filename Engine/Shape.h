#pragma once

#include "Vec2D.h"




class Shape
{
public:
	static std::vector<Vec2D> Circle(Vec2D center, int radius)
	{
		std::vector<Vec2D> model;
		Vec2D temp;

		float PI = acosf(-1.0);
		const int n = 30;


		for (int i = 0; i <= n; i++)
		{
			temp = Vec2D(center.get_x() + radius * cos( i * 2 * PI / n ), center.get_y() + radius * sin( i * 2 * PI / n ) );

			model.push_back(temp);
		}

		return model;
	}

	static std::vector<Vec2D> make_plot(std::vector<float> x, std::vector<float> y)
	{
		std::vector<Vec2D> model;
		Vec2D temp;

		for (size_t i = 0; i < x.size(); i++)
		{
			temp = { x[i], y[i] };
			model.push_back(temp);
		}

		return model;
	}


};