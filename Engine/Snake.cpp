#include "Snake.h"

void Snake::SnakeSegment::InitHead(const Location& in_loc)
{
	loc = in_loc;
	c = HeadColor;
}

void Snake::SnakeSegment::InitBody()
{
	c = BodyColor;
}

//void Snake::SnakeSegment::Init(const Location& in_loc)
//{
//
//}

void Snake::SnakeSegment::Follow(const SnakeSegment& next)
{
	loc = next.loc;
}

void Snake::SnakeSegment::Draw(Board& brd)
{
	brd.DrawElement(loc, c);
}

void Snake::SnakeSegment::MoveBy(const Location& dl)
{
	loc.x += dl.x;
	loc.y += dl.y;
}

Snake::Snake(const Location& loc)
{
	snake[0].InitHead(loc);
}

void Snake::MoveBy(const Location& dl)
{
	for (int i = cur_size - 1; i > 0; i--)
	{
		snake[i].Follow(snake[i - 1]);
	}

	snake[0].MoveBy(dl);

}

void Snake::Grow()
{
	snake[cur_size].InitBody();
	snake[cur_size].Follow(snake[cur_size - 1]);
	cur_size++;
}

void Snake::Draw(Board& brd)
{
	for (int i = 0; i < cur_size; i++)
	{
		snake[i].Draw(brd);
	}
}
