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
#include "RK4Math.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	rng(rd()),
	xDist(5, 750),
	yDist(5, 550),
	ct(gfx),
	cam(ct)
	//et1(Shape::Make(80, 200, 5))
{
	std::vector<float> t;
	std::vector< std::vector<float> > x;
	float t0 = 0.0f;
	float tf = 35.0f;
	float dt = 0.01f;
	
	std::vector<float> x_0, x_1;
	x = rk4({ 0.0f, 1.0f, 0.0f }, t0, tf, dt);
	
	for (auto& c : x)
	{
		x_0.push_back(c[0]);
		x_1.push_back(c[2]);
	}

	sing_points = find_singular_points({ 0.17f, 0.17f, 0.49f });

	std::vector<float> t_real, t_imag;

	for (auto& t : sing_points)
	{
		t_real.push_back(t[3].real());
		t_imag.push_back(t[3].imag());
	}

	Sing_Points = new Entity(Shape::MakePlot(t_real, t_imag));

	et1 = new Entity(Shape::MakePlot(x_0, x_1));

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

	const float speed = 10.0f;
	const float speed_2 = 10.0f;
	const float scale1 = 0.9f;
	const float scale2 = 1.1f;

	if (!shift_clicked)
	{
		if ( wnd.kbd.KeyIsPressed(VK_SHIFT) )
		{
			switch_control = !switch_control;
			shift_clicked = true;
		}

	}
	else
	{
		shift_clicked = false;
	}

	if (switch_control)
	{
		if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			cam.MoveBy({ 0.0f, speed });
		}
		if (wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			cam.MoveBy({ 0.0f, -speed });
		}
		if (wnd.kbd.KeyIsPressed(VK_LEFT))
		{
			cam.MoveBy({ -speed, 0.0f });
		}
		if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		{
			cam.MoveBy({ speed, 0.0f });
		}

		if (wnd.kbd.KeyIsPressed(VK_SPACE))
		{
			//et1->ScaleBy(scale1);
			cam.SetScale(cam.GetScale() * scale1);
		}
		if (wnd.kbd.KeyIsPressed(VK_CONTROL))
		{
			//et1->ScaleBy(scale2);
			cam.SetScale(cam.GetScale() * scale2);
		}
	}
	else
	{
		if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			cam.MoveBy({ 0.0f, speed });
		}
		if (wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			cam.MoveBy({ 0.0f, -speed });
		}
		if (wnd.kbd.KeyIsPressed(VK_LEFT))
		{
			cam.MoveBy({ -speed, 0.0f });
		}
		if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		{
			cam.MoveBy({ speed, 0.0f });
		}

		if (wnd.kbd.KeyIsPressed(VK_SPACE))
		{
			cam.SetScale(cam.GetScale() * scale1);
		}
		if (wnd.kbd.KeyIsPressed(VK_CONTROL))
		{
			cam.SetScale(cam.GetScale() * scale2);
		}
	}
}

void Game::ComposeFrame()
{
	//int x, y;
	Vec2D v = { 200, 250 };
	Vec2D v2 = { 300, 250 };
	Vec2D v3 = { 200, 350 };

	//std::vector<Vec2D> star = Shape::Make(80,200,5);
	std::vector<Vec2D> triangle = { v,v2,v3 };
	//gfx.DrawPolyline(star, { 255,10,10 });
	//gfx.DrawPolyline(triangle, { 169,40,0 });
	gfx.DrawRectangle(20, 20, Graphics::ScreenWidth - 20, Graphics::ScreenHeight - 20, { 255,255,255 });
	if (switch_control)
	{
		cam.DrawOpenPolyline(et1->GetPolyline(), { 0,240,0 });
	}
	else
	{
		cam.DrawScatterPlot(Sing_Points->GetPolyline(), { 250,0,0 });
	}

	if (wnd.mouse.LeftIsPressed())
	{
		gfx.DrawLine( v , (Vec2D)wnd.mouse.GetPos(), { 78, 153, 0 } );
	}


	
}


/**************************************************************/




