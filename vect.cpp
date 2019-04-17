#include <cmath>
#include <iostream>
#include <vector>
#include <iomanip>

#include "vect.h"
Vector3D::Vector3D(double a,double  b,double c)
{
	value[0] = a;
	value[1] = b;
	value[2] = c;
}

Vector3D::Vector3D()
{
}

Vector3D::~Vector3D()
{
}

const Vector3D operator* (const Vector3D& left, double c)
{
	return Vector3D(left.value[0] * c, left.value[1] * c, left.value[2] * c );
}

const Vector3D operator* (double c ,const Vector3D& left )
{
	return Vector3D(left.value[0] * c, left.value[1] * c, left.value[2] * c);
}

const Vector3D operator+ (const Vector3D& left, const Vector3D& rigth) {
	Vector3D fin;
	for (int i = 0; i < 3; i++)
		{ fin.value[i] = left.value[i] + rigth.value[i]; }
	return fin;
}

const Vector3D operator- (const Vector3D& left, const Vector3D& rigth)
{
	Vector3D fin;
	for (int i = 0; i < 3; i++ )
		{ fin.value[i] = left.value[i] - rigth.value[i]; }
	return fin;
}

double operator* (const Vector3D& left, const Vector3D& rigth)
{
	double fin=0;
	for (int i = 0; i < 3; i++)
		{ fin += left.value[i] * rigth.value[i]; }
	return fin;
}



