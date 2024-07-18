#pragma once

#include "Colors.h"
#include <string>


class Surface
{
public:
	Color* ptr_Pixel;
private:
	int width;
	int height;
public:
	Surface(std::string& filename);
	Surface(int w, int h);
	Surface(const Surface& s);
	~Surface();
	Surface operator=(Surface& s);
	void PutPixel(int x, int y, Color c);
	Color GetPixel(int x, int y) const;
	int GetWidth() const;
	int GetHeight() const;
};