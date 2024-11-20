#pragma once

#include "Graphics.h"

class Life
{
private:
	int life_counter = 3;


public:

	void DealDamage();
	void HealUp();
	bool NoMoreLifes() const;
	void DrawTable(const Vec2f& v, Graphics& gfx) const;


};