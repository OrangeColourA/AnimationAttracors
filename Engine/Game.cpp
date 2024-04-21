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
	if (!game_over)
	{
		for (auto& enemy : enemies)
		{
			game_over = game_over || enemy->Player_Hited(player);
		}

		for (auto& enemy : enemies)
		{
			enemy->Moving();
		}
		if (square.Got_Reached(player))
		{
			square.Change_location(xDist(rng), yDist(rng));
			counter++;
		}
		
		square.Pulsation();
		player.Moving();
	}

}

void Game::ComposeFrame()
{
	//gfx.DrawRectangle(1, 1, gfx.ScreenWidth - 1, gfx.ScreenHeight - 1, { 76,153,0 });

	for (auto& enemy : enemies)
	{
		enemy->Draw();
	}
	player.Draw();
	square.Draw();
	if (40 + counter * 25 <= gfx.ScreenWidth - 40)
	{
		gfx.DrawRectangle(40, 25, 40 + counter * 25, 35, { 0,0,204 });
	}
	else
	{
		gfx.DrawRectangle(40, 25, 40 + counter * 25, 35, { 0,0,204 });
		game_over = true;
	}
}


/**************************************************************/




void Game::DrawAimShape(int x, int y, Color c)
{
	gfx.PutPixel(x, y, c);

	gfx.PutPixel(x - 5, y, c);
	gfx.PutPixel(x - 4, y, c);
	gfx.PutPixel(x - 3, y, c);

	gfx.PutPixel(x + 3, y, c);
	gfx.PutPixel(x + 4, y, c);
	gfx.PutPixel(x + 5, y, c);

	gfx.PutPixel(x, y + 5, c);
	gfx.PutPixel(x, y + 4, c);
	gfx.PutPixel(x, y + 3, c);

	gfx.PutPixel(x, y - 5, c);
	gfx.PutPixel(x, y - 4, c);
	gfx.PutPixel(x, y - 3, c);
}

