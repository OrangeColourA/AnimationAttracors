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

#include <string>
#include "Shape.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	rng(rd()),
	xDist(0, 255),
	yDist(-300, 300)
{

	proj = proj.make_proj_matrix(
		static_cast<float>(Graphics::ScreenHeight)/ static_cast<float>(Graphics::ScreenHeight),
		fov,
		 1.f,
		 150.f
		);


	cube =
	{
		Vec3D( -50.f, -50.f, -50.f),		// 0
		Vec3D(  50.f, -50.f, -50.f),		// 1
		Vec3D(  50.f,  50.f, -50.f),		// 2
		Vec3D( -50.f,  50.f, -50.f),		// 3
		Vec3D( -50.f, -50.f,  50.f),		// 4
		Vec3D(  50.f, -50.f,  50.f),		// 5
		Vec3D(  50.f,  50.f,  50.f),		// 6
		Vec3D( -50.f,  50.f,  50.f)		    // 7

	};

	cube4 =
	{
		Vec4D( -10.f,  -10.f,   -10.f,   1.f ),		// 0
		Vec4D(  10.f,  -10.f,   -10.f,   1.f ),		// 1
		Vec4D(  10.f,   10.f,   -10.f,   1.f ),		// 2
		Vec4D( -10.f,   10.f,   -10.f,   1.f ),		// 3
		Vec4D( -10.f,  -10.f,    10.f,   1.f ),		// 4
		Vec4D(  10.f,  -10.f,    10.f,   1.f ),		// 5
		Vec4D(  10.f,   10.f,    10.f,   1.f ),		// 6
		Vec4D( -10.f,   10.f,    10.f,   1.f )		// 7

	};

	
	// lorenz model

	std::vector< std::vector<float> > res = rk4({0.f,1.f,0.f},0.f,60.f,0.01f);

	for (auto& r : res)
	{
		lorenz_model.push_back(Vec4D(r[0], r[1], r[2], 1.f));
	}

	index_buffer =
	{
		0, 1, 2, 3,		// front
		0, 4, 5, 1,		// top
		1, 5, 6, 2,		// right
		2, 6, 7, 3,		// bottom
		3, 7, 4, 0,		// left
		4, 7, 6, 5		// back
	};

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
	if (wnd.kbd.KeyIsPressed('W') )
	{
		y -= dy;
	}

	if (wnd.kbd.KeyIsPressed('S'))
	{
		y += dy;
	}

	if (wnd.kbd.KeyIsPressed('A'))
	{
		x += dx;
	}

	if (wnd.kbd.KeyIsPressed('D'))
	{
		x -= dx;
	}

	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		angle_x += angle_dx;
	}

	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		angle_x -= angle_dx;
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		angle_y += angle_dy;
	}

	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		angle_y -= angle_dy;
	}

	if (wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		angle_z += angle_dz;
	}

	if (wnd.kbd.KeyIsPressed(VK_CONTROL))
	{
		angle_z -= angle_dz;
	}

}



void Game::ComposeFrame()
{
	// cube drawing

	std::vector<Vec4D> model_draw = lorenz_model;

	for (auto& v : model_draw)
	{
		v = rotate(v, angle_x, angle_y, angle_z);
		v = v + Vec4D(0.f, 0.f, 60.f, 0.f);
		v = v + Vec4D(x,y,z,0.f);
		

		v = proj * v;
		v.w_divide();
	}

	for (size_t i = 1; i < lorenz_model.size(); i++)
	{
		//if (i % 4 == 3)
		//{
			
			float x1 = (model_draw[i].x + 1.f) * 0.5f * static_cast<float>(Graphics::ScreenWidth);
			float y1 = (model_draw[i].y + 1.f) * 0.5f * static_cast<float>(Graphics::ScreenHeight);
						   
						   
			float x2 = (model_draw[i - 1].x + 1.f) * 0.5f * static_cast<float>(Graphics::ScreenWidth) ;
			float y2 = (model_draw[i - 1].y + 1.f) * 0.5f * static_cast<float>(Graphics::ScreenHeight);
			

			gfx.DrawLine( Vec2D(x1, y1 ),
						  Vec2D(x2, y2 ),
						  Color(100,
							    176,
							    250)
			);
		//}
		/*else
		{
			
			float x1 = (cube_draw[index_buffer[i]].x + 1.f) * 0.5f * static_cast<float>(Graphics::ScreenWidth);
			float y1 = (cube_draw[index_buffer[i]].y + 1.f) * 0.5f * static_cast<float>(Graphics::ScreenHeight);
						   
						   
			float x2 = (cube_draw[index_buffer[i - 1]].x + 1.f) * 0.5f * static_cast<float>(Graphics::ScreenWidth);
			float y2 = (cube_draw[index_buffer[i - 1]].y + 1.f) * 0.5f * static_cast<float>(Graphics::ScreenHeight);
			

			gfx.DrawLine(Vec2D(x1 , y1 ),
						 Vec2D(x2 , y2 ),
						 Color(255, 255, 255));
		}*/
	}

}




/**************************************************************/





Vec4D Game::rotate(Vec4D v, float angle_x, float angle_y, float angle_z)
{
	Mat4 rot_x; rot_x = rot_x.make_rot_x_matrix(angle_x);
	Mat4 rot_y; rot_y = rot_y.make_rot_y_matrix(angle_y);
	Mat4 rot_z; rot_z = rot_z.make_rot_z_matrix(angle_z);

	v = rot_x * (rot_y * (rot_z * v));

	return v;
}

Vec4D Game::translate(Vec4D v, float dx, float dy, float dz)
{
	Mat4 T; T = T.make_transl_matrix(dx, dy, dz);
	v = T * v;
	return v;
}

