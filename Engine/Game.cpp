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
	snake(brd.GenerateLoc(rnd)),
	apple(brd, snake),
	gr(100,255)
	
{
	apple.Set(rnd);
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
		if (!key_pressed)
		{
			if (delta_loc.y != 1 && wnd.kbd.KeyIsPressed(VK_UP))
			{
				delta_loc = { 0, -1 };
				key_pressed = true;
			}
			else if (delta_loc.y != -1 && wnd.kbd.KeyIsPressed(VK_DOWN))
			{
				delta_loc = { 0, 1 };
				key_pressed = true;
			}
			else if (delta_loc.x != 1 && wnd.kbd.KeyIsPressed(VK_LEFT))
			{
				delta_loc = { -1, 0 };
				key_pressed = true;
			}
			else if (delta_loc.x != -1 && wnd.kbd.KeyIsPressed(VK_RIGHT))
			{
				delta_loc = { 1, 0 };
				key_pressed = true;
			}
		}

		if (count_frame == game_rate)
		{
			Location next = snake.Get_Next_Head_Location(delta_loc);
			key_pressed = false;

			if ( !brd.is_inside_board(next) || snake.is_in_segments(next) || ob_1.hit_obstacle( next ))
			{
				game_is_over = true;
			}
			else
			{
				if (wnd.kbd.KeyIsPressed(VK_SPACE))
				{
					snake.Grow( Color(gr(rnd), gr(rnd), gr(rnd)));
				}

				if (snake.Get_Head_Location().x == apple.GetLoc().x && snake.Get_Head_Location().y == apple.GetLoc().y)
				{
					snake.Grow( Color(gr(rnd), gr(rnd), gr(rnd)) );
					apple.Set(rnd);
				}

				snake.MoveBy(delta_loc);
				count_frame = 0;
			}


		}

		count_frame++;



		
	}
}

void Game::ComposeFrame()
{


	apple.Draw();

	snake.Draw(brd);


	brd.DrawBorder();


	std::pair<int, int> pos = wnd.mouse.GetPos();

	Location l = { pos.first, pos.second };
	l = brd.GetLocation_mousePos(l);
	if (brd.is_inside_board(l))
	{
		brd.DrawElement(l, Color(127 * (1 + std::sin(t)), 255, 255));
		if (wnd.mouse.LeftIsPressed())
		{
			ob_1.Init(l);
		}
	}

	ob_1.Draw(brd);

	t += 0.05f;

	
}


/**************************************************************/

