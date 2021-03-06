#include <cmath>
#include <iostream>
#include <vector>
#include <iomanip>


using namespace std;

class Vector3D
{
private:
    double value[3] ;
public:
	Vector3D(double a, double b, double c);
	Vector3D();
	~Vector3D();
    double getV(int a) const
    {
        return value[a];
    };
    setV(double a, int i)
    {
        value[i] = a;
    };

	//Vector3D(vector <double> v) : value(v) {}
	friend const Vector3D operator* (const Vector3D& left, double c); // v*c (c*v)
	friend const Vector3D operator* (double c, const Vector3D& left); //костыль?
	friend const Vector3D operator+ (const Vector3D& left, const Vector3D& rigth);// v+v
	friend const Vector3D operator- (const Vector3D& left, const Vector3D& rigth);// v-v
	friend double operator* (const Vector3D& left, const Vector3D& rigth);//v*v

};

const Vector3D operator* (const Vector3D& left, double c)
{
	return Vector3D(left.getV(0) * c, left.getV(1) * c, left.getV(2) * c );
}

const Vector3D operator* (double c ,const Vector3D& left )
{
	return Vector3D(left.getV(0) * c, left.getV(1) * c, left.getV(2) * c);
}

const Vector3D operator+ (const Vector3D& left, const Vector3D& rigth) {
	Vector3D fin;
	for (int i = 0; i < 3; i++)
		{ fin.value[i] = left.getV(i) + rigth.getV(i); }
	return fin;
}

const Vector3D operator- (const Vector3D& left, const Vector3D& rigth)
{
	Vector3D fin;
	for (int i = 0; i < 3; i++ )
		{ fin.value[i] = left.getV(i) - rigth.getV(i); }
	return fin;
}

double operator* (const Vector3D& left, const Vector3D& rigth)
{
	double fin=0;
	for (int i = 0; i < 3; i++)
		{ fin += left.getV(i) * rigth.getV(i); }
	return fin;
}


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

class Matrix3D
{
protected:
    double value[3][3];
public:
	Matrix3D();
	Matrix3D(double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8, double a9 );
	~Matrix3D();


	friend const Matrix3D operator* (const Matrix3D& left, double c); //m*c(c*m)
	friend const Matrix3D operator* (double c, const Matrix3D& rigth);
	friend const Matrix3D operator+ (const Matrix3D& left, const Matrix3D& rigth);//m+m
	friend const Matrix3D operator- (const Matrix3D& left, const Matrix3D& rigth);//m-m
	friend const Matrix3D operator* (const Matrix3D& left, const Matrix3D& rigth);//m*m
	friend const Vector3D operator* (const Matrix3D& left, const Vector3D& rigth); //m*v
	friend double det (const Matrix3D& left) ;//det



};

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
                double a = fin.getV(i);
                a += left.value[i][j] * rigth.getV(j);
				fin.setV(a,i);
		}
	}
	return fin;
}

 double det (const Matrix3D& left)
{
	double fin;
	fin = (left.value[0][0]* left.value[1][1] * left.value[2][2] + left.value[0][1] * left.value[1][2] * left.value[2][0] + left.value[1][0] * left.value[2][1] * left.value[0][2] - left.value[0][2] * left.value[1][1] * left.value[2][0] - left.value[0][1] * left.value[1][0] * left.value[2][2]- left.value[0][0] * left.value[2][1] * left.value[1][2]);
	return fin;
}

int main()
{
	Vector3D first(1, 2, 3), second(4, -2, -5),test;
	test = first * 7;
	cout << "first * 7 = ( " << test.getV(0) << ", " << test.getV(1) << ", " << test.getV(2) << " )" << endl;
	test = first + second;
	cout << "first + second = ( "<< test.getV(0) <<", " << test.getV(1) << ", " <<  test.getV(2) << " )" << endl;
	test = first - second;
	cout << "first - second = ( " << test.getV(0) << ", " << test.getV(1) << ", " << test.getV(2) << " )" << endl;
	double i = first * second;
	cout << "first * second = " << i << endl;

	Matrix3D firstM(1, 2, 3, 4, 5, -6, -6, -7, -3), secondM(0, 7, 5, -3, 2, -1, 5, 7, -3), testM;
	testM = firstM * 7;
/*	cout <<"firstM * 7 = ( " << testM.value[0][0] << ", " << testM.value[0][1] << ", " << testM.value[0][2] << endl;
	cout << testM.value[1][0] << ", " << testM.value[1][1] << ", " << testM.value[1][2] << endl;
	cout << testM.value[2][0] << ", " << testM.value[2][1] << ", " << testM.value[2][2] << ")"<< endl;*/
	testM = firstM + secondM;
/*	cout << "firstM + secondM = ( " << testM.value[0][0] << ", " << testM.value[0][1] << ", " << testM.value[0][2] << endl;
	cout << testM.value[1][0] << ", " << testM.value[1][1] << ", " << testM.value[1][2] << endl;
	cout << testM.value[2][0] << ", " << testM.value[2][1] << ", " << testM.value[2][2] << ")" << endl;*/
	testM = firstM - secondM;
/*	cout << "firstM - secondM = ( " << testM.value[0][0] << ", " << testM.value[0][1] << ", " << testM.value[0][2] << endl;
	cout << testM.value[1][0] << ", " << testM.value[1][1] << ", " << testM.value[1][2] << endl;
	cout << testM.value[2][0] << ", " << testM.value[2][1] << ", " << testM.value[2][2] << ")" << endl;*/
	testM = firstM * secondM;
/*	cout << "firstM * secondM = ( " << testM.value[0][0] << ", " << testM.value[0][1] << ", " << testM.value[0][2] << endl;
	cout << testM.value[1][0] << ", " << testM.value[1][1] << ", " << testM.value[1][2] << endl;
	cout << testM.value[2][0] << ", " << testM.value[2][1] << ", " << testM.value[2][2] << ")" << endl;*/
	test = firstM * first;
	cout << "firstM * first = ( " << test.getV(0) << ", " << test.getV(1) << ", " << test.getV(2) << " )" << endl;
	double a = det(firstM);
	cout << "det(firstM) = " << a;
}
