#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include "MainWindow.h"

class Player
{
private:
	int x;
	int y;
	int dx = 3;
	int dy = 3;
	int width = 17;
	Color c = { 255, 239, 0 };
	Graphics& gfx;
	MainWindow& wnd;
public:
	Player(int x, int y, Graphics& g, MainWindow& w);
	void Draw();
	void Moving();
	int Get_X();
	int Get_Y();
	int Get_W();
};