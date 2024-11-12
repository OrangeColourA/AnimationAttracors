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
	brd( gfx ),
	//apple( brd, snake ),
	rnd( std::random_device()() ),
	snake({ 3, 3 })
	
{
	
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
	
	if (!game_is_over)
	{

		if (delta_loc.y != 1 && wnd.kbd.KeyIsPressed(VK_UP))
		{
			delta_loc = { 0, -1 };
		}
		else if (delta_loc.y != -1 && wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			delta_loc = { 0, 1 };
		}
		else if (delta_loc.x != 1 && wnd.kbd.KeyIsPressed(VK_LEFT))
		{
			delta_loc = { -1, 0 };
		}
		else if (delta_loc.x != -1 && wnd.kbd.KeyIsPressed(VK_RIGHT))
		{
			delta_loc = { 1, 0 };
		}

		

		if (count_frame == game_rate)
		{
			if (wnd.kbd.KeyIsPressed(VK_SPACE))
			{
				snake.Grow();
			}
			snake.MoveBy(delta_loc);
			count_frame = 0;
		}
		count_frame++;
	}
}

void Game::ComposeFrame()
{
	
	
	//apple.Draw();

	snake.Draw(brd);


	brd.DrawBorder();
	
}


/**************************************************************/

