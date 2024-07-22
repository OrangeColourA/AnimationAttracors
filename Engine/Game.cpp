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
	yDist(-300, 300),
	rotate_x(
		Vec3D(1.f,        0.f,          0.f     ),
		Vec3D(0.f,    cosf(angle),   sinf(angle)),
		Vec3D(0.f,   -sinf(angle),   cosf(angle))
		)
{

	proj = proj.make_proj_matrix(
		static_cast<float>(Graphics::ScreenHeight)/ static_cast<float>(Graphics::ScreenHeight),
		fov,
		 1.f,
		 70.f
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

	//perspective divide

	

	// translate to center

	//Vec3D to_center(static_cast<float>(Graphics::ScreenWidth) / 2,
	//	static_cast<float>(Graphics::ScreenHeight) / 2, 0.0f);

	/*for (auto& v : cube)
	{
		v = v + to_center;
	}*/

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
	/*if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		Mat4 T;
		T.make_transl_matrix(0.0f, 0.0f, .00005f);

		for (auto& v : cube4)
		{
			v = T * v;
		}

	}

	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		Mat4 T;
		T.make_transl_matrix(0.0f, 0.0f, -.00005f);

		for (auto& v : cube4)
		{
			v = T * v;
		}

	}

	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		Mat4 T;
		T.make_transl_matrix(0.00005f, 0.0f, 0.0f);

		for (auto& v : cube4)
		{
			v = T * v;
		}

	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		for (auto& v : cube)
		{
			v = v + Vec3D(2.f, 0.f, 0.f);
		}*/

	//}

	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		for (auto& v : cube4)
		{
			v = Vec4D(
				v.x,
				cosf(angle) * v.y - sinf(angle) * v.z,
				sinf(angle) * v.y + cosf(angle) * v.z,
				1.f
			);
		};
	}

	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		for (auto& v : cube4)
		{
			v = Vec4D(
				v.x,
				cosf(angle) * v.y + sinf(angle) * v.z,
				-sinf(angle) * v.y + cosf(angle) * v.z,
				1.f
			);
		};
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		for (auto& v : cube4)
		{
			v = Vec4D(
				cosf(angle) * v.x + sinf(angle) * v.z,
				v.y,
				-sinf(angle) * v.x + cosf(angle) * v.z,
				1.f
			);
		};
	}

	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		for (auto& v : cube4)
		{
			v = Vec4D(
				cosf(angle) * v.x - sinf(angle) * v.z,
				v.y,
				sinf(angle) * v.x + cosf(angle) * v.z,
				1.f
			);
		};
	}

	if (wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		for (auto& v : cube4)
		{
			v = Vec4D(
				cosf(angle_z) * v.x - sinf(angle) * v.y,
				sinf(angle_z) * v.x + cosf(angle) * v.y,
				v.z,
				1.f
			);
		};
	}

	if (wnd.kbd.KeyIsPressed(VK_CONTROL))
	{
		for (auto& v : cube4)
		{
			v = Vec4D(
				cosf(angle_z) * v.x + sinf(angle) * v.y,
			   -sinf(angle_z) * v.x + cosf(angle) * v.y,
				v.z,
				1.f
			);
		};
	}

}

void Game::ComposeFrame()
{
	// cube drawing

	std::vector<Vec4D> cube_draw = cube4;

	for (auto& v : cube_draw)
	{
		v = v + Vec4D(0.f, 0.f, 50.f, 0.f);
		v = proj * v;
		v.w_divide();
	}

	for (size_t i = 1; i < index_buffer.size(); i++)
	{
		if (i % 4 == 3)
		{
			
			float x1 = (cube_draw[index_buffer[i]].x + 1.f) * 0.5f * static_cast<float>(Graphics::ScreenWidth);
			float y1 = (cube_draw[index_buffer[i]].y + 1.f) * 0.5f * static_cast<float>(Graphics::ScreenHeight);
						   
						   
			float x2 = (cube_draw[index_buffer[i - 3]].x + 1.f) * 0.5f * static_cast<float>(Graphics::ScreenWidth) ;
			float y2 = (cube_draw[index_buffer[i - 3]].y + 1.f) * 0.5f * static_cast<float>(Graphics::ScreenHeight);
			

			gfx.DrawLine( Vec2D(x1, y1 ),
						  Vec2D(x2, y2 ),
						  Color(255, 255, 255));
		}
		else
		{
			
			float x1 = (cube_draw[index_buffer[i]].x + 1.f) * 0.5f * static_cast<float>(Graphics::ScreenWidth);
			float y1 = (cube_draw[index_buffer[i]].y + 1.f) * 0.5f * static_cast<float>(Graphics::ScreenHeight);
						   
						   
			float x2 = (cube_draw[index_buffer[i - 1]].x + 1.f) * 0.5f * static_cast<float>(Graphics::ScreenWidth);
			float y2 = (cube_draw[index_buffer[i - 1]].y + 1.f) * 0.5f * static_cast<float>(Graphics::ScreenHeight);
			

			gfx.DrawLine(Vec2D(x1 , y1 ),
						 Vec2D(x2 , y2 ),
						 Color(255, 255, 255));
		}
	}

}




/**************************************************************/







