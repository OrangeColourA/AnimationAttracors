#include "Surface.h"
#include "ChiliWin.h"

#include <cassert>
#include <fstream>

Surface::Surface(int w, int h)
	:
	width(w),
	height(h),
	pPixel(new Color[w * h])
{}

Surface::Surface(const Surface& s)
	:
	Surface(s.width,s.height)
{

	for (int i = 0; i < height * width; i++)
	{
		pPixel[i] = s.pPixel[i];
	}
}

Surface& Surface::operator=(const Surface& s)
{
	delete[] pPixel;

	width = s.width;
	height = s.height;
	pPixel = new Color[width * height];

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			PutPixel(x, y, s.GetPixel(x, y));
		}
	}

	return *this;
	
}

Surface::Surface(const char* filename)
{
	std::ifstream input(filename, std::ios::binary);


	assert(input);

	BITMAPFILEHEADER bmpfile;
	input.read(reinterpret_cast<char*>(&bmpfile), sizeof(bmpfile));

	BITMAPINFOHEADER bmpinfo;
	input.read(reinterpret_cast<char*>(&bmpinfo), sizeof(bmpinfo));


	assert(bmpinfo.biCompression == 0);

	width = bmpinfo.biWidth;
	height = abs(bmpinfo.biHeight);

	pPixel = new Color[width * height];


	input.seekg(bmpfile.bfOffBits);
	int off_set = (4 - width % 4) % 4;


	if (bmpinfo.biHeight < 0)
	{
		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				PutPixel(x, y, Color(input.get(), input.get(), input.get()));
				if (bmpinfo.biBitCount == 32)
				{
					input.get();
				}
			}
			input.seekg(off_set, std::ios::cur);
		}
	}
	else
	{
		for (int y = height - 1; y >= 0; y--)
		{
			for (int x = 0; x < width; x++)
			{
				PutPixel(x, y, Color(input.get(), input.get(), input.get()));
				if (bmpinfo.biBitCount == 32)
				{
					input.get();
				}
			}
			input.seekg(off_set, std::ios::cur);
		}
	}

}

Surface::~Surface()
{
	delete[] pPixel;
	pPixel = nullptr;
}

Surface Surface::ApplyMeanFilter() const
{
	Surface changed(*this);


	int kernel_dim = 3;

	int* mean_kernel = new int[kernel_dim * kernel_dim];

	for (int i = 0; i < kernel_dim * kernel_dim; i++)
	{
		*(mean_kernel + i) = 1;
	}

	

	for (int y = 0; y < height - kernel_dim + 1; y++)
	{
		for (int x = 0; x < width - kernel_dim + 1; x++)
		{
			int red_average = 0;
			int green_average = 0;
			int blue_average = 0;

			for (int j = 0; j < kernel_dim; j++)
			{
				for (int i = 0; i < kernel_dim; i++)
				{
					Color temp = this->GetPixel(x + i, y + j);

					red_average   += mean_kernel[j + i * kernel_dim] * temp.GetR();
					green_average += mean_kernel[j + i * kernel_dim] * temp.GetG();
					blue_average  += mean_kernel[j + i * kernel_dim] * temp.GetB();
				}
			}

			red_average   /= kernel_dim * kernel_dim;
			green_average /= kernel_dim * kernel_dim;
			blue_average  /= kernel_dim * kernel_dim;

			for (int j = 0; j < kernel_dim; j++)
			{
				for (int i = 0; i < kernel_dim; i++)
				{
					changed.PutPixel(x + i, y + j, Color(red_average, green_average, blue_average));
				}
			}

		}
	}

	return changed;

}

Surface Surface::ApplyHorizontalFilter() const
{
	Surface changed(*this);


	int kernel_dim = 3;

	int* mean_kernel = new int[kernel_dim * kernel_dim];

	for (int i = 0; i < kernel_dim * kernel_dim; i++)
	{
		*(mean_kernel + i) = -(i + 1);
	}

	for (int i = 3; i < 6; i++)
	{
		*(mean_kernel + i) = 0;
	}

	for (int i = 6; i < 9; i++)
	{
		*(mean_kernel + i) = i - 5;
	}

	for (int y = 0; y < height - kernel_dim + 1; y++)
	{
		for (int x = 0; x < width - kernel_dim + 1; x++)
		{
			int red_average = 0;
			int green_average = 0;
			int blue_average = 0;

			for (int j = 0; j < kernel_dim; j++)
			{
				for (int i = 0; i < kernel_dim; i++)
				{
					Color temp = this->GetPixel(x + i, y + j);

					red_average += mean_kernel[i + j * kernel_dim] * temp.GetR();
					green_average += mean_kernel[i + j * kernel_dim] * temp.GetG();
					blue_average += mean_kernel[i + j * kernel_dim] * temp.GetB();
				}
			}

			red_average /= kernel_dim * kernel_dim;
			green_average /= kernel_dim * kernel_dim;
			blue_average /= kernel_dim * kernel_dim;

			for (int j = 0; j < kernel_dim; j++)
			{
				for (int i = 0; i < kernel_dim; i++)
				{
					changed.PutPixel(x + i, y + j, Color(red_average, green_average, blue_average));
				}
			}

		}
	}

	return changed;
	
}

Surface Surface::ApplyVerticalFilter() const
{
	Surface changed(*this);


	int kernel_dim = 3;

	int* mean_kernel = new int[kernel_dim * kernel_dim];

	for (int i = 0; i < kernel_dim * kernel_dim; i++)
	{
		mean_kernel[i*kernel_dim] = -(i + 1);
		mean_kernel[1 + i * kernel_dim] = 0;
		mean_kernel[2 + i * kernel_dim] = i + 1;
	}

	

	for (int y = 0; y < height - kernel_dim + 1; y++)
	{
		for (int x = 0; x < width - kernel_dim + 1; x++)
		{
			int red_average = 0;
			int green_average = 0;
			int blue_average = 0;

			for (int j = 0; j < kernel_dim; j++)
			{
				for (int i = 0; i < kernel_dim; i++)
				{
					Color temp = this->GetPixel(x + i, y + j);

					red_average += mean_kernel[i + j * kernel_dim] * temp.GetR();
					green_average += mean_kernel[i + j * kernel_dim] * temp.GetG();
					blue_average += mean_kernel[i + j * kernel_dim] * temp.GetB();
				}
			}

			red_average /= kernel_dim * kernel_dim;
			green_average /= kernel_dim * kernel_dim;
			blue_average /= kernel_dim * kernel_dim;

			for (int j = 0; j < kernel_dim; j++)
			{
				for (int i = 0; i < kernel_dim; i++)
				{
					changed.PutPixel(x + i, y + j, Color(red_average, green_average, blue_average));
				}
			}

		}
	}

	return changed;

}

void Surface::PutPixel(int x, int y, Color c)
{
	assert(x >= 0);
	assert(x < width);
	assert(y >= 0);
	assert(y < height);
	pPixel[x + y * width] = c;
}

Color Surface::GetPixel(int x, int y) const
{
	assert(x >= 0);
	assert(x < width);
	assert(y >= 0);
	assert(y < height);
	return pPixel[x + y * width];
}

int Surface::GetWidth() const
{
	return width;
}

int Surface::GetHeight() const
{
	return height;
}
