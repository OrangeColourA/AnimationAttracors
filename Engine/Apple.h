//#pragma once
//
//#include "Snake.h"
//
//
//class Apple
//{
//private:
//	Location loc = { 1,1 };
//	Board& brd;
//	Snake& snk;
//	std::mt19937 rng;
//	
//
//public:
//
//	Apple(Board& brd, Snake& snk) : brd(brd), snk(snk) {}
//
//	void Set()
//	{
//		std::uniform_int_distribution<int> pos_x(0, brd.GetWidth() - 1);
//		std::uniform_int_distribution<int> pos_y(0, brd.GetHeight() - 1);
//
//		bool apple_is_valid = false;
//		int x;
//		int y;
//
//		while (!apple_is_valid)
//		{
//			x = pos_x(rng);
//			y = pos_y(rng);
//			int i;
//
//			for (i = 0; i < snk.GetCurSize(); i++)
//			{
//				if (x == snk.GetElement(i).x && y == snk.GetElement(i).y)
//				{
//					break;
//				}
//			}
//
//			if (i == snk.GetCurSize())
//			{
//				apple_is_valid = true;
//			}
//		}
//		loc.x = x;
//		loc.y = y;
//	}
//
//	Location GetLoc()
//	{
//		return loc;
//	}
//
//	void Draw()
//	{
//		brd.DrawElement(loc, Colors::Red);
//	}
//};