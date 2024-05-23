#pragma once


#include <vector>




std::vector<float> ODE_model(std::vector<float> x)
{
	constexpr float alpha = 1.1f;
	constexpr float beta = 0.4f;
	constexpr float delta = 0.3f;
	constexpr float gamma = 0.1f;

	std::vector<float> x_dot = { alpha * x[0] - beta * x[0] * x[1],
								 delta * x[0] * x[1] - gamma * x[1] };

	return x_dot;
}


std::vector< std::vector<float> > rk4(std::vector<float> initial_values, std::vector<float> time, float dt)
{
	std::vector< std::vector<float> > res;
	res.push_back(initial_values);

	for (size_t k = 0; k < time.size(); k++)
	{
		float x_0 = res[k][0];
		float x_1 = res[k][1];

		std::vector<float> temp = { 0.0f, 0.0f };
		std::vector<float> k1, k2, k3, k4;

		k1 = ODE_model(res[k]);

		temp = { x_0 + dt * k1[0] / 2, x_1 + dt * k1[1] / 2 };
		k2 = ODE_model(temp);

		temp = { x_0 + dt * k2[0] / 2, x_1 + dt * k2[1] / 2 };
		k3 = ODE_model(temp);

		temp = { x_0 + dt * k3[0], x_1 + dt * k3[1] };
		k4 = ODE_model(temp);

		temp = { x_0 + dt * (k1[0] + 2 * k2[0] + 2 * k3[0] + k4[0]) / 6,
				x_1 + dt * (k1[1] + 2 * k2[1] + 2 * k3[1] + k4[1]) / 6 };
		res.push_back(temp);
	}

	return res;

}





