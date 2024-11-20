#pragma once
#include "Rectangle_f.h"
#include "Graphics.h"

class Boarder
{
private:
	Rectangle_f inner_walls;
	static constexpr int width = 13;
	static constexpr Color color = Colors::Blue;

public:
	Boarder(float left, float right, float top, float bottom)
		:
		inner_walls(left, right, top, bottom)
	{}
	void Draw(Graphics& gfx) const
	{
		// top boarder
		gfx.DrawRect(static_cast<int>(inner_walls.left) - width,
			static_cast<int>(inner_walls.top) - width,
			static_cast<int>(inner_walls.right) + width,
			static_cast<int>(inner_walls.top), color);

		// bottom boarder
		gfx.DrawRect(static_cast<int>(inner_walls.left) - width,
			static_cast<int>(inner_walls.bottom),
			static_cast<int>(inner_walls.right) + width,
			static_cast<int>(inner_walls.bottom) + width, color);

		// left boarder
		gfx.DrawRect(static_cast<int>(inner_walls.left) - width,
			static_cast<int>(inner_walls.top),
			static_cast<int>(inner_walls.left),
			static_cast<int>(inner_walls.bottom), color);

		// right boarder
		gfx.DrawRect(static_cast<int>(inner_walls.right),
			static_cast<int>(inner_walls.top),
			static_cast<int>(inner_walls.right) + width,
			static_cast<int>(inner_walls.bottom), color);
	}

	

	Rectangle_f GetRect() const
	{
		return inner_walls;
	}

	int GetWidth() const
	{
		return width;
	}

};