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
	snake( brd ),
	apple( brd, snake )
{
	snake.INIT();
	//apple.Set();
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

		if (delta_loc.x != 0 && delta_loc.y != 1 && wnd.kbd.KeyIsPressed(VK_UP))
		{
			delta_loc = { 0, -1 };
		}
		else if (delta_loc.x != 0 && delta_loc.y != -1 && wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			delta_loc = { 0, 1 };
		}
		else if (delta_loc.x != 1 && delta_loc.y != 0 && wnd.kbd.KeyIsPressed(VK_LEFT))
		{
			delta_loc = { -1, 0 };
		}
		else if (delta_loc.x != -1 && delta_loc.y != 0 && wnd.kbd.KeyIsPressed(VK_RIGHT))
		{
			delta_loc = { 1, 0 };
		}

		if (wnd.kbd.KeyIsPressed(VK_SPACE))
		{
			snake.Grow();
		}



		if (snake.GetHeadLoc().x == apple.GetLoc().x && snake.GetHeadLoc().y == apple.GetLoc().y)
		{
			snake.Grow();
			apple.Set();
		}
	}
}

void Game::ComposeFrame()
{
	/*std::mt19937 rng;
	std::uniform_int_distribution<int> rgb(0, 255);

	for (int i = 0; i < brd.GetWidth(); i++)
	{
		for (int j = 0; j < brd.GetHeight(); j++)
		{
			Location loc = { i, j };
			brd.DrawElement(loc, Color(rgb(rng), rgb(rng), rgb(rng)));
		}
	}*/

	if (!game_is_over)
	{
		
		if (snake.Head_Body_Colision(delta_loc) || snake.Head_Bordrer_Colision(delta_loc) )
		{
			game_is_over = true;
		}
	}
	
	if (!game_is_over)
	{
		snake.Move(delta_loc);
	}

	apple.Draw();

		
	

	snake.Draw();


	brd.DrawBorder();
	

	Sleep(200 - snake.GetCurSize() / 2);
	
}


/**************************************************************/

