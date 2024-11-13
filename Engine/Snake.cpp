#include "Snake.h"

void Snake::SnakeSegment::InitHead(const Location& in_loc)
{
	loc = in_loc;
	c = HeadColor;
}

void Snake::SnakeSegment::InitBody(Color col)
{
	//std::uniform_int_distribution<int> green(100, 255);
	c = col;
}

Location Snake::SnakeSegment::GetLocation() const
{
	return loc;
}

//void Snake::SnakeSegment::Init(const Location& in_loc)
//{
//
//}

void Snake::SnakeSegment::Follow(const SnakeSegment& next)
{
	loc = next.loc;
}

void Snake::SnakeSegment::Draw(Board& brd) const
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

void Snake::Grow(Color col)
{
	snake[cur_size].InitBody(col);
	snake[cur_size].Follow(snake[cur_size - 1]);
	cur_size++;
}

void Snake::Draw(Board& brd) const
{
	for (int i = 0; i < cur_size; i++)
	{
		snake[i].Draw(brd);
	}
}


Location Snake::Get_Head_Location() const
{
	return snake[0].GetLocation();
}

Location Snake::Get_Next_Head_Location(const Location& dl) const
{
	return {snake[0].GetLocation().x + dl.x, snake[0].GetLocation().y + dl.y };
}


bool Snake::is_in_segments(const Location& loc) const
{
	for (int i = 1; i < cur_size - 1; i++)
	{
		if (snake[i].GetLocation().x == loc.x && snake[i].GetLocation().y == loc.y)
		{
			return true;
		}
	}
	return false;
}

int Snake::Get_Size() const
{
	return cur_size;
}

Location Snake::GetElement(int i) const
{
	return snake[i].GetLocation();
}
