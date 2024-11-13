#include "Board.h"

void Board::DrawElement(const Location& l, Color c) const
{
	gfx.DrawRectDim(x_pos + l.x * ElementSize + 3    ,
		y_pos + l.y * ElementSize + 3,
		ElementSize - 3,
		ElementSize - 3, c);

}

void Board::DrawBorder() const
{
	
	gfx.DrawRectDim(x_pos - 10, y_pos - 10, 20 + BoardWidth * ElementSize, 10, Color(0, 30, 180));
	gfx.DrawRectDim(x_pos - 10, y_pos + BoardHeight * ElementSize, 20 + BoardWidth * ElementSize, 10, Color(0, 30, 180));

	gfx.DrawRectDim(x_pos - 10, y_pos, 10, BoardHeight * ElementSize, Color(0, 30, 180));
	gfx.DrawRectDim(x_pos + BoardWidth * ElementSize, y_pos, 10, BoardHeight * ElementSize, Color(0, 30, 180));
	
}

int Board::GetWidth() const
{
	return BoardWidth;
}

int Board::GetHeight() const
{
	return BoardHeight;
}

bool Board::is_inside_board(const Location& loc)
{
	return loc.x >= 0 && loc.x < BoardWidth && loc.y >= 0 && loc.y < BoardHeight;
}

Location Board::GenerateLoc(std::mt19937 rnd)
{
	std::uniform_int_distribution<int> pos_x(5, BoardWidth - 5);
	std::uniform_int_distribution<int> pos_y(5, BoardHeight - 5);

	return { pos_x(rnd), pos_y(rnd) };
}

Location Board::GetLocation_mousePos(const Location& Mouse_Pos) const
{
	return { (Mouse_Pos.x - x_pos) / ElementSize, (Mouse_Pos.y - y_pos) / ElementSize };
}
