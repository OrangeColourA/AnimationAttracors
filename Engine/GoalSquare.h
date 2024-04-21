#pragma once
#include "Graphics.h"
#include "Player.h"



class GoalSquare
{
private:
	int x;
	int y;
	int width = 17;
	Color c = { 255, 0, 0 };
	static constexpr int size = 51;
	int i = 0;
	unsigned char colors[size] = { 0,5,10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95,100,105,110,115,120,125,130,135,
		145,150,155,160,165,170,175,180,185,190,195,200,205,210,215,220,225,230,235,240,245,250,255 };
	Graphics& gfx;
public:
	GoalSquare(int x, int y, Graphics& g);
	void Draw();
	void Pulsation();
	bool Got_Reached(Player& p);
	void Change_location(int x, int y);
};
