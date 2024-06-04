#pragma once


#include <vector>
#include <complex>



std::vector<float> ODE_model(std::vector<float> x)
{
	constexpr float sigma = 10.0f;
	constexpr float rho = 28.0f;
	constexpr float beta = 2.66666667f;
	constexpr float m = 1.0f;

	std::vector<float> x_dot = { -sigma * x[0] + sigma * x[1],
								 rho * x[0] - m * x[1] - x[0] * x[2],
								 x[0] * x[1] - beta * x[2] };

	return x_dot;
}


std::vector< std::vector<float> > rk4(std::vector<float> initial_values, float t_0, float t_f, float dt)
{
	std::vector< std::vector<float> > res;
	res.push_back(initial_values);
	float epsilon = 0.01f;

	while (t_0 <= t_f)
	{
		float x_0 = res.back()[0];
		float x_1 = res.back()[1];
		float x_2 = res.back()[2];

		std::vector<float> temp = { 0.0f, 0.0f, 0.0f };
		std::vector<float> k1, k2, k3, k4;

		k1 = ODE_model(res.back());

		temp = { x_0 + dt * k1[0] / 2,
			     x_1 + dt * k1[1] / 2,
				 x_2 + dt * k1[2] / 2 };
		k2 = ODE_model(temp);

		temp = { x_0 + dt * k2[0] / 2,
				 x_1 + dt * k2[1] / 2,
				 x_2 + dt * k2[2] / 2 };
		k3 = ODE_model(temp);

		temp = { x_0 + dt * k3[0],
			     x_1 + dt * k3[1],
				 x_2 + dt * k3[2] };
		k4 = ODE_model(temp);

		temp = { x_0 + dt * (k1[0] + 2 * k2[0] + 2 * k3[0] + k4[0]) / 6,
				 x_1 + dt * (k1[1] + 2 * k2[1] + 2 * k3[1] + k4[1]) / 6,
				 x_2 + dt * (k1[2] + 2 * k2[2] + 2 * k3[2] + k4[2]) / 6 };
		res.push_back(temp);

		if (abs((k2[0] - k3[0]) / (k1[0] - k2[0])) < epsilon &&
			abs((k2[1] - k3[1]) / (k1[1] - k2[1])) < epsilon &&
			abs((k2[2] - k3[2]) / (k1[2] - k2[2])) < epsilon)
		{
			dt = dt + 0.01f;
		}
		else
		{
			dt = dt / 2;
		}

		t_0 = t_0 + dt;

	}

	return res;

}

std::vector<std::complex<float> > ODE_model_complex(std::vector<std::complex<float> > x)
{
	constexpr float sigma = 0.2f;
	constexpr float rho = 0.5f;
	constexpr float beta = 0.06f;
	constexpr float m = 0.003f;

	std::vector<std::complex<float> > x_dot = { -sigma * x[0] + sigma * x[1],
								 rho * x[0] - m * x[1] - x[0] * x[2],
								 x[0] * x[1] - beta * x[2] };

	return x_dot;
}

std::vector<std::complex<float> >  rk4_step_complex(std::vector<std::complex<float>> init_values, std::complex<float> dt)
{
	std::vector<std::complex<float> > next;

	std::complex<float> x_0 = init_values[0];
	std::complex<float> x_1 = init_values[1];
	std::complex<float> x_2 = init_values[2];

	std::vector<std::complex<float> > temp = { 0.0f, 0.0f, 0.0f };
	std::vector<std::complex<float> > k1, k2, k3, k4;

	k1 = ODE_model_complex(init_values);
	std::complex<float> divide(2.0f, 0.0f);
	std::complex<float> mult(6.0f, 0.0f);

	temp = { x_0 + dt * k1[0] / divide,
			 x_1 + dt * k1[1] / divide,
			 x_2 + dt * k1[2] / divide };
	k2 = ODE_model_complex(temp);

	temp = { x_0 + dt * k2[0] / divide,
			 x_1 + dt * k2[1] / divide,
			 x_2 + dt * k2[2] / divide };
	k3 = ODE_model_complex(temp);

	temp = { x_0 + dt * k3[0],
			 x_1 + dt * k3[1],
			 x_2 + dt * k3[2] };
	k4 = ODE_model_complex(temp);

	next = { x_0 + dt * (k1[0] + divide * k2[0] + divide * k3[0] + k4[0]) / mult,
			 x_1 + dt * (k1[1] + divide * k2[1] + divide * k3[1] + k4[1]) / mult,
			 x_2 + dt * (k1[2] + divide * k2[2] + divide * k3[2] + k4[2]) / mult };

	return next;

}

// Поиск особых точек

std::complex<float> Get_Q(std::vector<std::complex<float> > x)
{
	std::complex<float> Q(0.0f, 0.0f);
	std::vector<std::complex<float> > temp = ODE_model_complex(x);
	size_t N = x.size();

	for (size_t i = 0; i < N; i++)
	{
		Q += temp[i] * std::conj(x[i]);
	}

	return Q;

}

std::complex<float> Get_F(std::vector<std::complex<float> > x)
{
	std::complex<float> F(0.0f, 0.0f);
	size_t N = x.size();

	for (size_t i = 0; i < N; i++)
	{
		F += x[i] * std::conj(x[i]);
	}

	return F;

}

std::vector< std::vector< std::complex<float> > > find_singular_points(std::vector<float> init_values)
{
	// сначала получим значения для t = 1000

	float ds = 0.01f;
	float PI = acos(-1.0f);
	float phi = 0.0f;
	std::complex<float> t_0 (0.0f,0.0f);
	std::complex<float> t_f (1036.0f, 0.0f);
	const size_t N = init_values.size();
	std::complex<float> dt(ds * cos(phi), ds * sin(phi));
	std::complex<float> dt_1_0 = dt;

	std::vector< std::complex<float> > temp; // для вычислений

	for (auto& c : init_values)
	{
		std::complex<float> new_c (c, 0.0f);
		temp.push_back(new_c);
	}



	while (t_0.real() < t_f.real())
	{
		temp = rk4_step_complex(temp, dt); // в итоге получим начальные условия в точке t = 1000 в temp
		t_0 += dt;
	}
	

	std::complex<float> Q(0.0f, 0.0f), F(0.0f, 0.0f);
	//ds = 2.0f;
	phi = PI / 2;
	dt = { ds * cos(phi), ds * sin(phi) };

	std::vector<std::vector< std::complex<float> >> res;  // для результата
	
	t_f = { 2000.0f, 0.0f };
	std::complex<float> T(37.0f, 0.0f);

	std::vector<std::complex<float> > prev_step_values;
	std::complex<float> prev_t;

	while (t_0.real() < t_f.real())
	{
		prev_step_values = temp;	// решение в t = 1050
		prev_t = t_0;				// t = 1050

		F = { 0.0f,0.0f };
		Q = { 0.0f,0.0f };

		phi = PI / 2;
		dt = { ds * cos(phi), ds * sin(phi) };

		while (F.real() < 100000.0f)
		{
			temp = rk4_step_complex(temp, dt);
			F = Get_F(temp);
			Q = Get_Q(temp);
			phi = -arg(Q);
			dt = { ds * cos(phi), ds * sin(phi) };
			t_0 += dt;
		}
		res.push_back(temp);		
		res.back().push_back(t_0);

		t_0 = prev_t;
		temp = prev_step_values;
		

		while (t_0.real() < (prev_t + T).real())
		{
			temp = rk4_step_complex(temp, dt_1_0); // в итоге получим начальные условия в точке t = t + T в temp
			t_0 += dt_1_0;
		}

		//code
		
	}
	return res;

}