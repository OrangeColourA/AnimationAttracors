#pragma once

#include "Board.h"
#include <random>


// TO DO:
// in snake.h
// Add correct moving checking - DONE
// 
// Add borders collision with snake  - DONE
// 
// and snake with body - DONE

// in apple.h
// add feature: apple should not appear inside of snake body


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
	static constexpr size_t MAX_SIZE = Board::BoardWidth * Board::BoardHeight;
	size_t current_size = 3;

	float head_x = 0.f;
	float head_y = 0.f;
	float velocity = 0.5f;

	SnakeSegment snake[MAX_SIZE];

public:

	Snake(Board& brd) : brd(brd) {}

	void INIT(std::mt19937& rng, float v)
	{
		
		std::uniform_int_distribution<int> pos_x(3, brd.GetWidth() - 3);
		std::uniform_int_distribution<int> pos_y(3, brd.GetHeight() - 3);

		snake[0].loc.x = pos_x(rng);
		snake[0].loc.y = pos_y(rng);
		
		head_x = static_cast<float>(snake[0].loc.x);
		head_y = static_cast<float>(snake[0].loc.y);
		velocity = v;

		for (int i = 1; i < current_size; i++)
		{
			snake[i].loc.x = snake[i - 1].loc.x - 1;
			snake[i].loc.y = snake[i - 1].loc.y;
			snake[i].color = Color(0, snake[i].green + i, 0);
		}
	}

	// Draw, Move, Grow

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

		head_x += delta_loc.x * velocity;
		head_y += delta_loc.y * velocity;

		if (static_cast<int>(head_x) != snake[0].loc.x || static_cast<int>(head_y) != snake[0].loc.y)
		{
			for (size_t segm = current_size - 1; segm > 0; segm--)
			{
				snake[segm].loc = { snake[segm - 1].loc.x, snake[segm - 1].loc.y };
			}

			snake[0].loc = { static_cast<int>(head_x), static_cast<int>(head_y) };
		}

	}


	bool Head_Body_Colision(const Location& dl)
	{
		//bool colided = false;

		for (int i = 1; i < current_size; i++)
		{
			if (   snake[0].loc.x + dl.x == snake[i].loc.x
				&& snake[0].loc.y + dl.y == snake[i].loc.y
				|| snake[0].loc.x		 == snake[i].loc.x
				&& snake[0].loc.y		 == snake[i].loc.y)
			{
				return true;
			}
		}

		return false;

	}

	bool Head_Bordrer_Colision(const Location& dl)
	{
		if (snake[0].loc.x + dl.x >= brd.GetWidth()  || snake[0].loc.x + dl.x < 0 ||
			snake[0].loc.y + dl.y >= brd.GetHeight() || snake[0].loc.y + dl.y < 0)
		{
			return true;
		}
		return false;
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

	size_t GetCurSize()
	{
		return current_size;
	}

	Location GetElement(int i)
	{
		return snake[i].loc;
	}


	


};


