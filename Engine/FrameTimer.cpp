#include "FrameTimer.h"

FrameTimer::FrameTimer()
{
	last = std::chrono::steady_clock::now();
}

float FrameTimer::Mark()
{
	auto temp_last = last;
	last = std::chrono::steady_clock::now();

	std::chrono::duration<float> dif = last - temp_last;

	return dif.count();
}
