#pragma once
#include "Graphics.h"
#include "Player.h"



class Enemy
{
private:
	int x;
	int y;
	int dx = 2;
	int dy = 2;
	int direction;
	int width = 17;
	bool Hit_Player = false;
	Graphics& gfx;
	Color c = { 76, 153, 0 };
public:
	Enemy(int x, int y, int direction, Graphics& g);
	void Moving();
	void Draw();
	bool Player_Hited(Player& p);
};