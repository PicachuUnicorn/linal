#include <cmath>
#include <iostream>
#include <vector>
#include <iomanip>

#include "matr.h"
const Matrix3D operator* (const Matrix3D& left, double c)
{
	Matrix3D fin;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			fin.value[i][j] = left.value[i][j] * c;
		}
	}
	return fin;
}

const Matrix3D operator* (double c, const Matrix3D& rigth)
{
	Matrix3D fin;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			fin.value[i][j] = rigth.value[i][j] * c;
		}
	}
	return fin;
}

const Matrix3D operator+ (const Matrix3D& left, const Matrix3D& rigth)
{
	Matrix3D fin;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			fin.value[i][j] = left.value[i][j] + rigth.value[i][j];
		}
	}
	return fin;
}

const Matrix3D operator- (const Matrix3D& left, const Matrix3D& rigth)
{
	Matrix3D fin;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			fin.value[i][j] = left.value[i][j] - rigth.value[i][j];
		}
	}
	return fin;
}

const Matrix3D operator* (const Matrix3D& left, const Matrix3D& rigth)
{
	Matrix3D fin(0,0,0,0,0,0,0,0,0);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				fin.value[i][j] += left.value[i][k] * rigth.value[k][j];
			}
		}
	}
	return fin;
}

const Vector3D operator* (const Matrix3D& left, const Vector3D& rigth)
{
	Vector3D fin(0,0,0);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
				fin.value[i] += left.value[i][j] * rigth.value[j];
		}
	}
	return fin;
}

/*double det (const Matrix3D& left)
{
	double fin;
	fin = (left.value[0][0]* left.value[1][1] * left.value[2][2] + left.value[0][1] * left.value[1][2] * left.value[3][0] + left.value[1][0] * left.value[2][1] * left.value[0][2] - left.value[0][2] * left.value[1][1] * left.value[2][0] - left.value[0][1] * left.value[1][0] * left.value[2][2]- left.value[0][0] * left.value[2][1] * left.value[1][2]);
	return fin;
}*/

Matrix3D::Matrix3D()
{
}

Matrix3D::Matrix3D(double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8, double a9)
{
	value[0][0] = a1; value[0][1] = a2; value[0][2] = a3;
	value[1][0] = a4; value[1][1] = a5; value[1][2] = a6;
	value[2][0] = a7; value[2][1] = a8; value[2][2] = a9;
}

Matrix3D::~Matrix3D()
{
}

