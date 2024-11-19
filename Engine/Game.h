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

#include "Sound.h"
#include "SoundEffect.h"

#include "FrameTimer.h"
#include "Ball.h"
#include "Brick.h"
#include "Paddle.h"
#include "Boarder.h"

#include <random>



class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel(float dt);
	/********************************/
	/*  User Functions              */
	



	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	
	std::mt19937 rng;

	Sound shit_sound;
	SoundEffect shit_ansamble;
	
	Ball ball;
	Rectangle_f walls;
	Paddle pad;
	Boarder wall;
	
	static constexpr int grid_width = 8;
	static constexpr int grid_height = 4;
	static constexpr int num_bricks = 32;
	Brick arr_br[num_bricks];
	Color arr_colors[4] = { Colors::Yellow,Colors::Cyan, Colors::Red, Colors::Green };
	
	Brick test_br;
	FrameTimer frame_timer;
	//float dt;

	/********************************/
	
	
};


