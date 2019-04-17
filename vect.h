#ifndef VECT_H
#define VECT_H

#include <cmath>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Vector3D
{
private:

public:
	Vector3D(double a, double b, double c);
	Vector3D();
	~Vector3D();
	double value[3] ;

	//Vector3D(vector <double> v) : value(v) {}
	friend const Vector3D operator* (const Vector3D& left, double c); // v*c (c*v)
	friend const Vector3D operator* (double c, const Vector3D& left); //костыль?
	friend const Vector3D operator+ (const Vector3D& left, const Vector3D& rigth);// v+v
	friend const Vector3D operator- (const Vector3D& left, const Vector3D& rigth);// v-v
	friend double operator* (const Vector3D& left, const Vector3D& rigth);//v*v

};


#endif // VECT_H
