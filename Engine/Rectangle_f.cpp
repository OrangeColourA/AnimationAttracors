#include "Rectangle_f.h"

Rectangle_f::Rectangle_f(float l, float r, float t, float b)
	:
	left(l),
	right(r),
	top(t),
	bottom(b)
{}

Rectangle_f::Rectangle_f(const Vec2f& top_left, const Vec2f& bottom_right)
	:
	Rectangle_f(top_left.x, bottom_right.x, top_left.y, bottom_right.y)
{}

Rectangle_f::Rectangle_f(const Vec2f& top_left, float width, float height)
	:
	Rectangle_f(top_left.x, top_left.x + width, top_left.y, top_left.y + height)
{
}

Rectangle_f& Rectangle_f::operator=(const Rectangle_f& rec)
{
	left = rec.left;
	right = rec.right;
	top = rec.top;
	bottom = rec.bottom;
	return *this;
}

bool Rectangle_f::is_intersect(const Rectangle_f& rect)
{
	return right > rect.left &&
			left < rect.right &&
			top < rect.bottom &&
			bottom > rect.top;
}

Vec2f Rectangle_f::GetCenter() const
{
	return Vec2f((left + right) / 2, (top + bottom) / 2);
}

Rectangle_f Rectangle_f::GetRect(const Vec2f& top_left, const Vec2f& bottom_right)
{
	return Rectangle_f(top_left, bottom_right);
}
