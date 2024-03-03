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
	gfx( wnd )
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
	

	ControlObject(x_player1, y_player1);
	ControlPlayer2(x_player2, y_player2);

	MovingObject(x_ball, y_ball, dx_ball, dy_ball);
	MovingObject(x_ball2, y_ball2, dx_ball2, dy_ball2);

	BoundaryCheckForBox(x_coord, y_coord);
	CheckInFrame(x_player1, y_player1);
	CheckInFrame(x_player2, y_player2);
	BallBouncing(x_ball, y_ball, dx_ball, dy_ball);
	BallBouncing(x_ball2, y_ball2, dx_ball2, dy_ball2);


}

void Game::ComposeFrame()
{

	DrawGameFrame(50, 50, 750, 550, {50,250,50});

	//DrawRectangle(x_coord, y_coord, x_coord + 10,y_coord + 10,{250,0,0});

	DrawRectangle(x_ball, y_ball, x_ball + 10, y_ball + 10, { 250,0,0 });
	DrawRectangle(x_ball2, y_ball2, x_ball2 + 10, y_ball2 + 10, { 250,0,0 });

	DrawRectangle(x_player1, y_player1, x_player1 + 10, y_player1 + 70, { 20, 20, 180 });
	DrawRectangle(x_player2, y_player2, x_player2 + 10, y_player2 + 70, { 170, 20, 20 });


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


void Game::DrawBox(int x, int y, Color c)
{
	for (int i = x - 5; i <= x + 5; i++)
	{
		gfx.PutPixel(i, y + 5, c);
		gfx.PutPixel(i, y - 5, c);
	}
	for (int i = y - 5; i <= y + 5; i++)
	{
		gfx.PutPixel(x - 5, i, c);
		gfx.PutPixel(x + 5, i, c);
	}
}

void Game::BoundaryCheckForBox(int& x, int& y)
{
	if (x > gfx.ScreenWidth - 6)
	{
		x = gfx.ScreenWidth - 6;
	}
	if (x < 6)
	{
		x = 6;
	}
	if (y > gfx.ScreenHeight - 6)
	{
		y = gfx.ScreenHeight - 6;
	}
	if (y < 6)
	{
		y = 6;
	}
}

void Game::ControlObject(int& x, int& y)
{

	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		y -= dy;
	}

	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		y += dy;
	}

}

void Game::ControlPlayer2(int& x, int& y)
{
	if (wnd.kbd.KeyIsPressed(VK_SHIFT))
	{
		y -= dy;
	}

	if (wnd.kbd.KeyIsPressed(VK_CONTROL))
	{
		y += dy;
	}
}


void Game::DrawRectangle(int x0, int y0, int x1, int y1, Color c)
{
	for (int x = x0; x <= x1; x++)
		for (int y = y0; y <= y1; y++)
			gfx.PutPixel(x, y, c);
}

void Game::DrawGameFrame(int x0, int y0, int x1, int y1, Color c)
{
	DrawRectangle(x0, y0, x1, y0 + 20, c);
	DrawRectangle(x0, y0 + 20, x0 + 20, y1 - 20, c);
	DrawRectangle(x0, y1 - 20, x1, y1, c);
	DrawRectangle(x1 - 20, y0 + 20, x1, y1, c);
}

void Game::CheckInFrame(int& x, int& y)
{
	if (x + 10  > 729)
	{
		x =  719;
	}
	if (x < 71)
	{
		x = 71;
	}
	if (y + 70 > 529)
	{
		y = 529 - 70;
	}
	if (y < 71)
	{
		y = 71;
	}

}

void Game::MovingObject(int& x, int& y, int& dx, int& dy)
{
	//CheckInFrame( x, y);
	x += dx;
	y += dy;
}

void Game::BallBouncing(int& x, int& y, int& dx, int& dy)
{
	if (x + 10 > 729)
	{
		dx = -dx;
	}
	if (x < 71)
	{
		dx = -dx;
	}
	if (y + 10 > 529)
	{
		dy = -dy;
	}
	if (y < 71)
	{
		dy = -dy;
	}

	//for player 1

	if (x < 90 && y <= y_player1 + 70 && y >= y_player1)
		dx = -dx;

	if (x > 700 && y <= y_player2 + 70 && y >= y_player2)
		dx = -dx;
}
