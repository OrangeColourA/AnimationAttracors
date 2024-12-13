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
	//shit_sound(L"gameoy.wav"),
	//shit_ansamble({L"fart0.wav", L"fart1.wav", L"fart2.wav" }),
	frame_timer(),
	calc_timer(),
	v0( 0.f ,-0.5f, 1.f, 1.f),
	v1( 0.3f, 0.f , 1.f, 1.f),
	v2(-0.3f, 0.5f, 1.f, 1.f)
	/*flower("flower.bmp")*/
{
	/*calc_timer.Mark();

	red_flower = flower.ApplyRedFilter();
	green_flower = flower.ApplyGreenFilter();
	blue_flower = flower.ApplyBlueFilter();
	blury_image = flower.ApplyMeanFilter();
	horizontal_image = flower.ApplyHorizontalFilter();
	vertical_image = flower.ApplyVerticalFilter();

	float cal_time = calc_timer.Mark();*/

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


	if (wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		angle_y = (angle_y + PI / 12.f * dt);
	}
	if (wnd.kbd.KeyIsPressed(VK_SHIFT))
	{
		angle_y = (angle_y - PI / 12.f * dt);
	}

	if (wnd.kbd.KeyIsPressed('D'))
	{
		angle_z = (angle_z + PI / 12.f * dt);
	}
	if (wnd.kbd.KeyIsPressed('F'))
	{
		angle_z = (angle_z - PI / 12.f * dt);
	}

}

void Game::ComposeFrame()
{


	Mat4f M_view = Mat4f::make_view_transformation(Graphics::ScreenWidth, Graphics::ScreenHeight);
	Mat4f M_rot_y = Mat4f::make_rotation_y(angle_y);
	Mat4f M_rot_z= Mat4f::make_rotation_z(angle_z);


	Vec4f v0_draw = M_view * (M_rot_z * (M_rot_y * v0));
	Vec4f v1_draw = M_view * (M_rot_z * (M_rot_y * v1));
	Vec4f v2_draw = M_view * (M_rot_z * (M_rot_y * v2));


	gfx.DrawLine(static_cast<Vec2f>(v0_draw), static_cast<Vec2f>(v1_draw), Colors::Cyan);
	gfx.DrawLine(static_cast<Vec2f>(v0_draw), static_cast<Vec2f>(v2_draw), Colors::Cyan);
	gfx.DrawLine(static_cast<Vec2f>(v1_draw), static_cast<Vec2f>(v2_draw), Colors::Cyan);

	/*gfx.DrawSurfaceSprite(x, y, flower);
	if (wnd.kbd.KeyIsPressed('R'))
	{
		gfx.DrawSurfaceSprite(x + 620, y, red_flower);
	}
	else if (wnd.kbd.KeyIsPressed('G'))
	{
		gfx.DrawSurfaceSprite(x + 620, y, green_flower);
	}
	else if (wnd.kbd.KeyIsPressed('B'))
	{
		gfx.DrawSurfaceSprite(x + 620, y, blue_flower);
	}

	if (wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		gfx.DrawSurfaceSprite(x + 620, y, horizontal_image);
	}
	else if (wnd.kbd.KeyIsPressed('F'))
	{
		gfx.DrawSurfaceSprite(x + 620, y, vertical_image);
	}
	else if (wnd.kbd.KeyIsPressed(VK_SHIFT))
	{
		gfx.DrawSurfaceSprite(x + 620, y, blury_image);
	}*/
}


/**************************************************************/

