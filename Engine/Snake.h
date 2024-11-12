#pragma once

#include "Board.h"
#include <random>





class Snake
{
private:
	class SnakeSegment
	{
	private:
		Location loc;
		Color c;
	public:
		void InitHead(const Location& in_loc);
		void InitBody();
		//void Init(const Location& in_loc);
		void Follow(const SnakeSegment& next);
		void Draw(Board& brd);
		void MoveBy(const Location& dl);
	};

	static constexpr int size = 100;
	static constexpr Color HeadColor = Colors::Yellow;
	static constexpr Color BodyColor = Colors::Green;
	int cur_size = 1;
	SnakeSegment snake[size];

public:
	Snake(const Location& loc);
	void MoveBy(const Location& dl);
	void Grow();
	void Draw(Board& brd);

};


