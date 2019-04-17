#ifndef MATR_H
#define MATR_H

#include <cmath>
#include <iostream>
#include <vector>
#include <iomanip>

#include "vect.h"
class Matrix3D
{
public:
	Matrix3D();
	Matrix3D(double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8, double a9 );
	~Matrix3D();
	double value[3][3];

	friend const Matrix3D operator* (const Matrix3D& left, double c); //m*c(c*m)
	friend const Matrix3D operator* (double c, const Matrix3D& rigth);
	friend const Matrix3D operator+ (const Matrix3D& left, const Matrix3D& rigth);//m+m
	friend const Matrix3D operator- (const Matrix3D& left, const Matrix3D& rigth);//m-m
	friend const Matrix3D operator* (const Matrix3D& left, const Matrix3D& rigth);//m*m
	friend const Vector3D operator* (const Matrix3D& left, const Vector3D& rigth); //m*v
	double det (const Matrix3D& left) {};//det

private:

};


#endif // MATR_H
