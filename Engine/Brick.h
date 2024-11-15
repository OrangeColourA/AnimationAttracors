#pragma once

#include "Graphics.h"
#include "Rectangle_f.h"


class Brick
{
private:
	Rectangle_f body;
	static constexpr int width = 150;
	static constexpr int heigth = 30;
	Color color;
	bool destroyed = false;
	Graphics& gfx;
public:
	
	Brick(Graphics& g, int x, int y, Color c);

	void Draw();
	void Destroy();
	Rectangle_f GetRect();
};