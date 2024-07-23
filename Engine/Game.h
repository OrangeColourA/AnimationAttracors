/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Vec2D.h"
#include "Matrix.h"
//#include "RK4Math.h"
//#include "SpheresRender.h"

//#include "Element.h"
//
//#include "Circles.h"

//#include <complex>
#include <random>
#include <limits>

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */


	Vec4D rotate(Vec4D v, float angle_x, float angle_y, float angle_z);
	Vec4D translate(Vec4D v, float dx, float dy, float dz);


	
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> xDist;
	std::uniform_real_distribution<float> yDist;
	
	std::vector<Vec3D> cube;
	std::vector<Vec4D> cube4;
	std::vector<size_t> index_buffer;
	std::vector<Vec4D> lorenz_model;

	//std::vector<Vec2D> screen_model;
	//Mat3 rotate_x;
	Mat4 proj;

	/*Mat3 rotate_y;
	Mat3 rotate_z;*/
	bool moving = false;

	const float PI = acosf(-1);

	float fov = 0.33f * PI;

	float angle_x = 0.0f;
	float angle_y = 0.0f;
	float angle_z = 0.0f;
	float angle_dx = 0.005f * PI;
	float angle_dy = 0.005f * PI;
	float angle_dz = 0.005f * PI;

	float x = 0.f;
	float y = 0.f;
	float z = 0.f;
	float dx = 0.5f;
	float dy = 0.5f;
	float dz = 0.5f;


	Color c = { 0,255,0 };
	/********************************/
	
	
};


