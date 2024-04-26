/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	rng( rd() ),
	xDist( 5, 750 ),
	yDist( 5, 550 ),
	player( xDist(rng), yDist(rng), gfx, wnd ),
	square( xDist(rng), yDist(rng), gfx )
{
	for (int i = 0; i < size; i++)
	{
		enemies[i] = new Enemy(xDist(rng), yDist(rng), xDist(rng), gfx);
	}

}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	x_pos = wnd.mouse.GetPosX();
	y_pos = wnd.mouse.GetPosY();
	
}

void Game::ComposeFrame()
{
	//int x, y;

	if (wnd.mouse.LeftIsPressed())
	{
		gfx.DrawLine(250, 200, x_pos, y_pos, { 78, 153, 0 });
		
	}
	//gfx.DrawLine(250, 200, 450, 300, { 150, 2, 0 });
	//gfx.DrawLine(250, 200, 300, 450, { 2, 153, 0 });
	//gfx.DrawLine(250, 200, 250, 500, { 7, 3, 250 });
	/*
	gfx.DrawLine(250, 200, x_pos, y_pos, { 78, 153, 0 });
	gfx.DrawLine(250, 200, x_pos, y_pos, { 78, 153, 0 });
	gfx.DrawLine(250, 200, x_pos, y_pos, { 78, 153, 0 });
	*/
}


/**************************************************************/




