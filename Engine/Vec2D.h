#pragma once
#include <vector>
//#include "Matrix.h"

class Vec2D
{
public:
	float x;
	float y;

public:
	Vec2D();
	Vec2D(float x_new, float y_new);
	Vec2D(std::pair<int, int> p);
	Vec2D(std::pair<float, float> p);
	float get_x();
	float get_y();
	void norm();
	float length();
	void operator+=( Vec2D ) ;
	void operator-=(Vec2D);
	void operator*=(float);
	Vec2D operator+(Vec2D);

};



class Vec3D
{
private:
	float x;
	float y;
	float z;
public:
	Vec3D();
	Vec3D(const Vec3D& v) ;
	Vec3D(float x_new, float y_new, float z_new);
	
	float get_x() const;
	float get_y() const;
	float get_z() const;
	
	void z_divide();

	float length();
	Vec3D normalize();

	Vec3D operator-(Vec3D sub);
	Vec3D operator+(Vec3D add);
	float& operator[](int n);
	float operator*(Vec3D mult);
	Vec3D operator*(float c);
};


class Vec4D
{
public:
	float x;
	float y;
	float z;
	float w;

	Vec4D();
	Vec4D(const Vec4D& v);
	Vec4D(float x_new, float y_new, float z_new, float w_new);

	void w_divide();

	float length();
	Vec4D normalize();
	   
	Vec4D operator-(Vec4D sub);
	Vec4D operator+(Vec4D add);
	
	float operator*(Vec4D mult);
	Vec4D operator*(float c);

	

};