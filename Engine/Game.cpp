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
	ct(gfx)
	//et1(Shape::Make(80, 200, 5))
{

	std::vector<float> t;
	std::vector< std::vector<float> > x;
	float t0 = 0.0f;
	float tf = 100.0f;
	float dt = 0.01f;
	while (t0 < tf)
	{
		t.push_back(t0);
		//y.push_back(cos(t0));
		t0 += dt;
	}
	std::vector<float> x_0, x_1;
	x = rk4({ 2.0f, 5.0f }, t, dt);
	for (auto& c : x)
	{
		x_0.push_back(c[0]);
		x_1.push_back(c[1]);
	}


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

	const float speed = 3.0f;
	const float scale1 = 0.9f;
	const float scale2 = 1.1f;
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		et1->TranslateBy({ 0.0f, speed });
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		et1->TranslateBy({ 0.0f, -speed });
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		et1->TranslateBy({ -speed, 0.0f });
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		et1->TranslateBy({ speed, 0.0f });
	}
	
	if (wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		et1->ScaleBy(scale1);
	}
	if (wnd.kbd.KeyIsPressed(VK_CONTROL))
	{
		et1->ScaleBy(scale2);
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
	
	ct.DrawOpenPolyline(et1->GetPolyline(), {25,250,10});

	if (wnd.mouse.LeftIsPressed())
	{
		gfx.DrawLine( v , (Vec2D)wnd.mouse.GetPos(), { 78, 153, 0 });
	}


	
}


/**************************************************************/




