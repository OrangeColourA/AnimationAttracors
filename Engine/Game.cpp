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
	shit_sound(L"gameoy.wav"),
	shit_ansamble({L"fart0.wav", L"fart1.wav", L"fart2.wav" }),
	frame_timer()
	
{
	VertexBuffer[0] = Vec4f( 0.5f, -0.5f, 0.5f, 1.f);
	VertexBuffer[1] = Vec4f(-0.5f, -0.5f, 0.5f, 1.f);
	VertexBuffer[2] = Vec4f( 0.5f, -0.5f, 0.5f, 1.f);
	VertexBuffer[3] = Vec4f( 0.5f, -0.5f, 0.5f, 1.f);
	VertexBuffer[4] = Vec4f( 0.5f, -0.5f, 0.5f, 1.f);
	VertexBuffer[5] = Vec4f( 0.5f, -0.5f, 0.5f, 1.f);
	VertexBuffer[6] = Vec4f( 0.5f, -0.5f, 0.5f, 1.f);
	VertexBuffer[7] = Vec4f( 0.5f, -0.5f, 0.5f, 1.f);

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

	
}

void Game::ComposeFrame()
{

	gfx.DrawModel(VertexBuffer, 8, IndexBuffer, 30);

	

	
}


/**************************************************************/

