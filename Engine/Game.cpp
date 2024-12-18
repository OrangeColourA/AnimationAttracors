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
	rng(std::random_device()()),
	shit_sound(L"arkpad.wav"),
	shit_ansamble({L"fart0.wav", L"fart1.wav", L"fart2.wav" }),
	frame_timer(),
	ball(gfx, Vec2f(190.f,400.f)),
	walls(2.5f, static_cast<float>(Graphics::ScreenWidth) -2.5f,2.5f, static_cast<float>(Graphics::ScreenHeight) - 2.5f),
	pad(gfx, Vec2f(400.f,550.f)),
	test_br(255,215, Colors::Magenta),
	wall(50.f, static_cast<float>(Graphics::ScreenWidth) - 50.f, 25.f, static_cast<float>(Graphics::ScreenHeight) - 25.f)
	
{
	state = running;

	for (int i = 0; i < grid_height; i++)
	{
		for (int j = 0; j < grid_width; j++)
		{
			arr_br[j + i * grid_width].Init( 80 + j * Brick::GetWidth(), 50 + i * Brick::GetHeight(), arr_colors[i]);
		}
	}
}

void Game::Go()
{
	gfx.BeginFrame();
	
	float elapsedTime = frame_timer.Mark();
	while (elapsedTime > 0.0f)
	{
		float temp_time = std::min(0.0025f, elapsedTime);
		UpdateModel(temp_time);
		elapsedTime -= 0.0025f;
	}
	
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel(float dt)
{
	
	if (state == running)
	{
		ball.Move(dt);
		pad.Move(wnd.kbd, dt);
		//pad.Do_wall_collide(walls);
		pad.Do_wall_collide(wall.GetRect());
		if (ball.Hit_paddle(pad))
		{
			shit_sound.Play();
		}


		if (ball.Detect_brick_collioson(test_br))
		{
			ball.Handle_brick_collision(test_br);
			pad.ResetCooldown();
			shit_sound.Play();
		}


		if (ball.Do_wall_collide(wall.GetRect(), damageDealt))
		{
			if (damageDealt)
			{
				life.DealDamage();
				if (life.NoMoreLifes())
				{
					state = game_over;
				}
				else
				{
					state = wait_space_key;
				}
			}
			
			pad.ResetCooldown();
		}
		/*if (ball.Do_wall_collide(walls))
		{
			pad.ResetCooldown();
		}*/

		bool collision_happened = false;
		int collision_index;
		//int new_collision_index;
		float cur_lowest_distance;
		float new_distance;
		for (int i = 0; i < num_bricks; i++)
		{
			if (ball.Detect_brick_collioson(arr_br[i]))
			{
				if (collision_happened)
				{

					new_distance = (arr_br[i].GetCenter() - ball.Get_pos()).GetLengthSq();
					if (new_distance < cur_lowest_distance)
					{
						cur_lowest_distance = new_distance;
						collision_index = i;
					}

				}
				else
				{
					cur_lowest_distance = (arr_br[i].GetCenter() - ball.Get_pos()).GetLengthSq();
					collision_index = i;
					collision_happened = true;
				}
			}
		}

		if (collision_happened)
		{
			ball.Handle_brick_collision(arr_br[collision_index]);
			pad.ResetCooldown();
			shit_sound.Play();
		}
	}
	else if (state == wait_space_key)
	{
		if (wnd.kbd.KeyIsPressed(VK_SPACE))
		{
			//gfx.DrawRectDim(Vec2f(400.f, 400.f), 10, 10, Colors::Magenta);
			ball.ResetPos(wall.GetRect());
			state = running;
			damageDealt = false;
		}
	}
	else if (state == game_over)
	{

	}
}

void Game::ComposeFrame()
{
	gfx.DrawCoolBackground(wall.GetRect());
	if (state == running)
	{
		ball.Draw();
	}
	life.DrawTable(Vec2f(wall.GetRect().left - wall.GetWidth(), wall.GetRect().bottom), gfx);
	pad.Draw();
	for (int i = 0; i < num_bricks; i++)
	{
		arr_br[i].Draw(gfx);
	}
	test_br.Draw(gfx);

	wall.Draw(gfx);

	if (state == game_over)
	{
		gfx.DrawEndTitle(wall.GetRect().GetCenter());
	}

}


/**************************************************************/

