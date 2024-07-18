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
	framebuffer(Graphics::ScreenHeight * Graphics::ScreenWidth),
	fragmentbuffer(Graphics::ScreenHeight * Graphics::ScreenWidth),
	sphere(Vec3D(-2.0f,0.0f, -2.0f), 1.0f)
{
	for (size_t j = 0; j < Graphics::ScreenHeight; j++)
	{
		for (size_t i = 0; i < Graphics::ScreenWidth; i++)
		{
			framebuffer[i + j * Graphics::ScreenWidth] = Vec3D(j / static_cast<float>(Graphics::ScreenHeight),
				i / static_cast<float>(Graphics::ScreenWidth), 0.0f);
		}
	}

	render_sphere(sphere);



	for (size_t i = 0; i < Graphics::ScreenHeight * Graphics::ScreenWidth; i++)
	{
		fragmentbuffer[i] = Color(
			static_cast<char>(255 * framebuffer[i][0]),
			static_cast<char>(255 * framebuffer[i][1]),
			static_cast<char>(255 * framebuffer[i][2])
		);
	}

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
	

}

Vec3D Game::cast_ray( Vec3D& orig, Vec3D& dir, Sphere& sphere)
{
	float sphere_dist = std::numeric_limits<float>::max();

	if (!sphere.ray_intersect(orig, dir, sphere_dist))
	{
		return Vec3D(0.4f, 0.4f, 0.3f);
	}

	return Vec3D(0.2f,0.7f,0.8f);
}

void Game::render_sphere( Sphere& sphere )
{
	float width = Graphics::ScreenWidth;
	float height = Graphics::ScreenHeight;

	for (size_t j = 0; j < height; j++) {
		for (size_t i = 0; i < width; i++) {

			float x = (2 * (i + 0.5) / (float)width - 1) * tan(fov / 2.) * width / (float)height;
			float y = -(2 * (j + 0.5) / (float)height - 1) * tan(fov / 2.);
			
			Vec3D dir = Vec3D(x,y,-1.0f).normalize();

			framebuffer[i + j * width] = cast_ray(Vec3D(0.0f, 0.0f, 0.0f), dir, sphere);
		}
	}
}

bool Game::scene_intersect(Vec3D& orig, Vec3D& dir, std::vector<Sphere>& spheres, Vec3D& hit, Vec3D& N, Material& material)
{

	float a;



	return false;
}

void Game::ComposeFrame()
{
	gfx.render(fragmentbuffer);

}


/**************************************************************/




