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
		int green = 50;
		Color color = Color(0, green, 0);
		bool initialised = false;
		

	};

	Board& brd;
	static constexpr size_t MAX_SIZE = 400;
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

	Location GetHeadLoc()
	{
		return snake[0].loc;
	}

	void Grow()
	{
		snake[current_size].loc = snake[current_size - 1].loc;
		snake[current_size].color = Color(0, (snake[current_size].green + current_size) % 255, 0);
		current_size++;
	}

	int GetCurSize()
	{
		return current_size;
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
			snake[i].color = Color(0, snake[i].green + i, 0);
		}
	}


};


