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
	ball(gfx, Vec2f(300.f,300.f)),
	walls(2.5f, static_cast<float>(Graphics::ScreenWidth) -2.5f,2.5f, static_cast<float>(Graphics::ScreenHeight) - 2.5f),
	br(gfx, 300, 400, Colors::Red)
	
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

	dt = frame_timer.Mark();

	/*if ( wnd.kbd.KeyIsPressed('W') )
	{
		y -= dy * dt;
	}
	
	if (wnd.kbd.KeyIsPressed('A'))
	{
		x -= dx * dt;
	}
	
	if (wnd.kbd.KeyIsPressed('S'))
	{
		y += dy * dt;
	}
	
	if (wnd.kbd.KeyIsPressed('D'))
	{
		x += dx * dt;
	}*/

	ball.Move(dt);
	if (ball.Do_wall_collide(walls))
	{
		shit_sound.Play();
	}
	
	if (ball.Hit_brick(br.GetRect()))
	{
		shit_sound.Play();
		br.Destroy();
	}
}

void Game::ComposeFrame()
{

	ball.Draw();
	br.Draw();
}


/**************************************************************/

