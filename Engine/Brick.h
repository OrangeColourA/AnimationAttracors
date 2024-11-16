#pragma once

#include "Graphics.h"
#include "Rectangle_f.h"


class Brick
{
private:
	Rectangle_f body;
	static constexpr int width = 80;
	static constexpr int heigth = 30;
	Color color;
	bool destroyed = false;
	bool initialized = false;
	//
public:
	Brick() = default;
	Brick(int x, int y, Color c);

	void Init(int x, int y, Color c);
	void Draw(Graphics& g) const;
	void Destroy();
	bool is_destroyed() const;
	Rectangle_f GetRect() const;
	static int GetWidth() ;
	static int GetHeight() ;
};