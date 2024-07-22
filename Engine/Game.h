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
//#include "SpheresRender.h"

//#include "Element.h"
//
//#include "Circles.h"

#include <complex>
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
	//std::vector<Vec2D> screen_model;
	Mat3 rotate_x;
	Mat4 proj;

	/*Mat3 rotate_y;
	Mat3 rotate_z;*/
	bool moving = false;

	double fov = 0.33f * acos(-1);
	float angle_z = 0.005f * acosf(-1);
	float angle = 0.01f * acosf(-1);

	Color c = { 0,255,0 };
	/********************************/
	
	
};


