#include <stdio.h>
#include <stdbool.h>

#include "triangleSolver.h"
#include <math.h>

#define PI 3.141592654

char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = "Not a triangle";
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle";
	}
	else if ((side1 == side2 && side1 != side3) || 
		(side1 == side3 && side1 != side2))
	{
		result = "Isosceles triangle";
	}
	else {
		result = "Scalene triangle";
	}

	return result;
}
/*
void triangleInsideAngle(int num[3], float angle[3]){
	int side1 = num[0];
	int side2 = num[1];
	int side3 = num[2];
	
}

double convert(double radian){
	return(radian * (180/PI));
}
*/