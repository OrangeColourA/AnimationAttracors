#pragma once

#include "Board.h"
#include <random>

class Snake
{
private:
	class SnakeSegment
	{
	public:
		Location loc;
		Color color = Colors::Green;
		bool initialised = false;
		

	};

	Board& brd;
	static constexpr size_t MAX_SIZE = 100;
	size_t current_size = 3;

	SnakeSegment snake[MAX_SIZE];

public:

	// Draw, Move, Grow

	Snake(Board& brd) : brd(brd) {}

	void Draw()
	{
		for (int i = 0; i < current_size; i++)
		{
			brd.DrawElement(snake[i].loc, snake[i].color);
		}
	}

	void Move(const Location& delta_loc)
	{
		// from tail to head

		for (int segm = current_size - 1; segm > 0; segm--)
		{ 
			snake[segm].loc = { snake[segm - 1].loc.x, snake[segm - 1].loc.y };
		}

		snake[0].loc = { snake[0].loc.x + delta_loc.x,  snake[0].loc.y + delta_loc.y };

	}


	void INIT()
	{
		std::mt19937 rng;
		std::uniform_int_distribution<int> pos_x(3, brd.GetWidth() - 3);
		std::uniform_int_distribution<int> pos_y(3, brd.GetHeight() - 3);

		snake[0].loc.x = pos_x(rng);
		snake[0].loc.y = pos_y(rng);
		snake[0].initialised = true;

		for (int i = 1; i < current_size; i++)
		{
			snake[i].loc.x = snake[i - 1].loc.x - 1;
			snake[i].loc.y = snake[i - 1].loc.y;
		}
	}


};


