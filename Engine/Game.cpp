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


#include "Shape.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	rng(rd()),
	xDist(0, 255),
	yDist(-300, 300)

{
	
	//std::vector< std::vector<float> > Solution; //= rk4({ 1.0f, 0.0f,1.0f }, 0.0f, 35.0f, 0.01f);
	Solution.push_back(current_value);
	std::vector< float > x;
	std::vector< float > y;

	//Vec2D pos = { Graphics::ScreenWidth / 2, Graphics::ScreenHeight / 2 + 250.0f};

	for (auto& c : Solution)
	{
		x.push_back(  10.0f *  c[0] + pos.get_x()  );
		y.push_back( -10.0f *  c[2] + pos.get_y()  );
	}

	model = Shape::make_plot(x, y);

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
	if (!start)
	{
		if (wnd.kbd.KeyIsPressed(VK_SPACE))
		{
			start = true;
		}
	}



	if (start)
	{
		if (t < 10000.0f)
		{
			current_value = rk4_step(current_value, 0.01f);
			Solution.push_back(current_value);

			model.push_back({  10.0f * Solution.back()[0] + pos.get_x(),
							  -10.0f * Solution.back()[2] + pos.get_y() });

			t += 0.01f;
		}
	}

}

void Game::ComposeFrame()
{



	
	Vec2D v = { Graphics::ScreenWidth / 2, 250.0f };

	if (wnd.mouse.LeftIsPressed())
	{
		Vec2D temp = (Vec2D)wnd.mouse.GetPos();
		gfx.DrawThickLine( v , temp, 4,{ 78, 153, 0 } );
	}

	//int temp = static_cast<int>(Solution.back()[0]) % 255;

	gfx.DrawOpenPolyline(model);
	
}


/**************************************************************/




