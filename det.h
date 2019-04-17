#ifndef DET_H
#define DET_H

#include <cmath>
#include <iostream>
#include <vector>
#include <iomanip>

#include "matr.h"

double det (const Matrix3D& left){
    double fin;
	fin = (left.value[0][0]* left.value[1][1] * left.value[2][2] + left.value[0][1] * left.value[1][2] * left.value[2][0] + left.value[1][0] * left.value[2][1] * left.value[0][2] - left.value[0][2] * left.value[1][1] * left.value[2][0] - left.value[0][1] * left.value[1][0] * left.value[2][2]- left.value[0][0] * left.value[2][1] * left.value[1][2]);
	return fin;}

#endif // DET_H
