#pragma once

#include "Board.h"
#include <random>


// Check that snake is not colide with itself



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
		void InitBody(Color col);
		Location GetLocation() const;
		void Follow(const SnakeSegment& next);
		void Draw(Board& brd) const;
		void MoveBy(const Location& dl);
	};

	static constexpr int size = 500;
	static constexpr Color HeadColor = Colors::Yellow;
	static constexpr Color BodyColor = Colors::Green;
	int cur_size = 1;
	SnakeSegment snake[size];

public:
	Snake(const Location& loc);
	void MoveBy(const Location& dl);
	void Grow(Color col);
	void Draw(Board& brd) const;
	
	Location Get_Head_Location() const;
	Location Get_Next_Head_Location(const Location& dl) const;
	bool is_in_segments(const Location& loc) const;

	int Get_Size() const;
	Location GetElement(int i) const;
};


