#include "Life.h"

void Life::DealDamage()
{
	life_counter--;
}

void Life::HealUp()
{
	life_counter++;
}

bool Life::NoMoreLifes() const
{
	return life_counter == 0;
}

void Life::DrawTable(const Vec2f& v, Graphics& gfx) const
{
	const int width = 20;
	const int height = 50;
	const int between = 5; 

	for (int i = 0; i < life_counter - 1; i++)
	{
		gfx.DrawRectDim(v + Vec2f(-(width + between), -((i + 1)*height + i * between)), 20, 50, Colors::LightGray);
	}

}
