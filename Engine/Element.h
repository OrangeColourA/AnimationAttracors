#pragma once

#include "Graphics.h"

class Element
{
public:
	Element(Graphics& g, Vec2D p, Color c)
		:
		gfx(g),
		pos(p),
		c(c)
	{}

	void DrawElement() 
	{
		if (
			pos.get_x() > 0 && pos.get_x() < Graphics::ScreenWidth &&
			pos.get_y() > 0 && pos.get_y() < Graphics::ScreenHeight
			)
		{
			gfx.PutPixel((int)pos.get_x(), (int)pos.get_y(), c);
		}
	}

	void MoveElement()
	{

		float mass1 = 2000.0f;
		float mass2 = 800.0f;
		float mass3 = 600.0f;
		float mass4 = 1400.0f;

		Vec2D vel1 = {  (Graphics::ScreenWidth / 4 - pos.get_x()),
					    (Graphics::ScreenHeight / 2 - pos.get_y()) };	


		Vec2D vel2 = {  (0.75f * Graphics::ScreenWidth - pos.get_x()),
					    (Graphics::ScreenHeight / 2 - pos.get_y()) };

		Vec2D vel3 = { (Graphics::ScreenWidth / 2 - pos.get_x()),
						(Graphics::ScreenHeight / 4 - pos.get_y()) };


		Vec2D vel4 = { (Graphics::ScreenWidth / 2 - pos.get_x()),
						(0.75f * Graphics::ScreenHeight - pos.get_y()) };
		

		pos += { (mass1 * vel1.get_x()) / (vel1.length() * vel1.length() * vel1.length()),
				 (mass1 * vel1.get_y()) / (vel1.length() * vel1.length() * vel1.length())};

		pos += { (mass2 * vel2.get_x()) / (vel2.length() * vel2.length() * vel2.length()),
			     (mass2 * vel2.get_y()) / (vel2.length() * vel2.length() * vel2.length())};

		pos += { (mass3* vel3.get_x()) / (vel3.length() * vel3.length() * vel3.length()),
			     (mass3* vel3.get_y()) / (vel3.length() * vel3.length() * vel3.length())};

		pos += { (mass4 * vel4.get_x()) / (vel4.length() * vel4.length() * vel4.length()),
			     (mass4 * vel4.get_y()) / (vel4.length() * vel4.length() * vel4.length())};
	}

private:
	Graphics& gfx;
	Vec2D pos;
	Color c;
};


class Asteroid
{
public:



private:
	Graphics& gfx;
	std::vector< Element* > els;
};


class World
{
public:
	World( Graphics& g)
		:
		elements(),
		gfx(g)
	{}

	void CreateElement(Vec2D p, Color c)
	{
		elements.push_back(new Element(gfx, p, c));
	}

	void CreateLineOfElements(Vec2D v0, Vec2D v1, Color c)
	{
		int delta_x = ((int)v1.get_x() - (int)v0.get_x());
		int delta_y = ((int)v1.get_y() - (int)v0.get_y());

		int dx = 1;
		int dy = 1;

		if (delta_y < 0)
		{
			dy = -1;
		}
		if (delta_x < 0)
		{
			dx = -1;
		}

		float sloap = (float)delta_y / (float)delta_x;

		int x_pos = (int)v0.get_x();
		int y_pos = (int)v0.get_y();

		if (abs(sloap) < 1.0f)
		{
			int p_k = 2 * delta_y * dy - delta_x * dx;

			while (x_pos != (int)v1.get_x())
			{
				Vec2D temp = { (float)x_pos, (float)y_pos };
				CreateElement(temp, c);

				if (p_k < 0)
				{
					p_k = p_k + 2 * delta_y * dy;
				}
				else
				{
					p_k = p_k + 2 * delta_y * dy - 2 * delta_x * dx;
					y_pos += dy;
				}

				x_pos += dx;
			}
		}
		else
		{
			int p_k = 2 * delta_x * dx - delta_y * dy;

			while (y_pos != (int)v1.get_y())
			{
				Vec2D temp = { (float)x_pos, (float)y_pos };
			
				CreateElement( temp , c);
				

				if (p_k < 0)
				{
					p_k = p_k + 2 * delta_x * dx;
				}
				else
				{
					p_k = p_k + 2 * delta_x * dx - 2 * delta_y * dy;
					x_pos += dx;
				}

				y_pos += dy;
			}
		}
	}

	void Draw_World()
	{
		for (auto& el : elements)
		{
			el->DrawElement();
		}
	}

	void Move_World()
	{
		for (auto& el : elements)
		{
			el->MoveElement();
		}
	}

private:
	std::vector<Element*> elements;
	//std::vector< Asteroid* > asteroids;
	Graphics& gfx;
};



