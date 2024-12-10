#pragma once
#include "Colors.h"


class Surface
{
private:
	int width;
	int height;
	Color* pPixel = nullptr;
public:
	Surface() = default;
	Surface(int w, int h);
		/*:
		width(w),
		height(h),
		pPixel(new Color[w*h])
	{}*/

	Surface(const Surface& s);
	Surface& operator=(const Surface& s);
	Surface(const char* filename);
	~Surface();
	
	Surface ApplyMeanFilter() const;
	Surface ApplyHorizontalFilter() const;
	Surface ApplyVerticalFilter() const;
	void PutPixel(int x, int y, Color c);
	Color GetPixel(int x, int y) const;
	int GetWidth() const;
	int GetHeight() const;
};

