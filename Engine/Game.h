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
	void DrawAimShape(int x, int y, Color c);
	void DrawBox(int x, int y, Color c);
	void BoundaryCheckForBox(int& x, int& y);
	void ControlObject(int& x, int& y);
	void ControlPlayer2(int& x, int& y);
	void DrawRectangle(int x0, int y0, int x1, int y1, Color c);
	void DrawGameFrame(int x0, int y0, int x1, int y1, Color c);

	void CheckInFrame(int& x, int& y);
	void MovingObject(int& x, int& y, int& dx, int& dy);
	void BallBouncing(int& x, int& y, int& dx, int& dy);
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	int x_coord = 400;
	int y_coord = 300;

	int x_ball = 420;
	int y_ball = 320;
	int x_ball2 = 300;
	int y_ball2 = 200;

	int x_player1 = 80;
	int y_player1 = 250;
	int x_player2 = 710;
	int y_player2 = 250;

	int dx = 3;
	int dy = 5;
	int dx_ball = 5;
	int dy_ball = 5;
	int dx_ball2 = -5;
	int dy_ball2 = 5;

	bool isBallHitSth = false;

	Color c = { 0,255,0 };
	/********************************/
	
	
};


