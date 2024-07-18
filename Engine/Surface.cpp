#include "Surface.h"
#include <cassert>
#include <fstream>
#include <Windows.h>

Surface::Surface(std::string& filename)
{
	std::ifstream input(filename, std::ios::binary);
	assert( input );

	BITMAPFILEHEADER bmFileHeader;

	input.read(reinterpret_cast<char*>(&bmFileHeader), sizeof(bmFileHeader));

	BITMAPINFOHEADER bmInfoHeader;

	input.read(reinterpret_cast<char*>(&bmInfoHeader), sizeof(bmInfoHeader));

	assert(bmInfoHeader.biBitCount == 24);// || bmInfoHeader.biBitCount == 32);
	assert(bmInfoHeader.biCompression == BI_RGB);

	width = bmInfoHeader.biWidth;
	height = bmInfoHeader.biHeight;

	ptr_Pixel = new Color[width * height];

	input.seekg(bmFileHeader.bfOffBits);

	int padding = (4 - (3 * width) % 4) % 4;
	//if (height >=)
	for (int y = height - 1; y >= 0; y--)
	{
		for (int x = 0; x < width; x++)
		{
			PutPixel(x, y, Color( input.get(),input.get(),input.get() ));

		}
		input.seekg(padding, std::ios::cur);
	}

}

Surface::Surface(int w, int h)
	:
	width(w),
	height(h),
	ptr_Pixel(new Color[w*h])
{}

Surface::Surface(const Surface& s)
	:
	Surface(s.GetWidth(), s.GetHeight())
{
	
	for (int i = 0; i < width * height; i++)
	{
		ptr_Pixel[i] = s.ptr_Pixel[i];
	}
}

Surface::~Surface()
{
	delete[] ptr_Pixel;
	ptr_Pixel = nullptr;
}

Surface Surface::operator=(Surface& s)
{
	width = s.GetHeight();
	height = s.GetHeight();

	delete[] ptr_Pixel;
	ptr_Pixel = new Color[width * height];

	for (int i = 0; i < width * height; i++)
	{
		ptr_Pixel[i] = s.ptr_Pixel[i];
	}

	return *this;
}

void Surface::PutPixel(int x, int y, Color c)
{
	assert(x >= 0);
	assert(x < int(width));
	assert(y >= 0);
	assert(y < int(height));
	ptr_Pixel[width * y + x] = c;
}

Color Surface::GetPixel(int x, int y) const
{
	assert(x >= 0);
	assert(x < int(width));
	assert(y >= 0);
	assert(y < int(height));
	return ptr_Pixel[width * y + x];
}

int Surface::GetWidth() const
{
	return width;
}

int Surface::GetHeight() const
{
	return height;
}
