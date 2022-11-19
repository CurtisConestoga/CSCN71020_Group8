#include <stdio.h>
#include <stdbool.h>

#include "triangleSolver.h"
#include <math.h>

#define PI 3.141592654
#define RADIAN_DEGREES 57.2958
#define TOTALDEGREES 180

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


void triAng(int side, int side1, int side2)
{
	double angle1, angle2, angle3;

	// Angle formula using radians. Angle returned in radians due to acos. 1 radian is default to: 57.2958
	angle1 = RADIAN_DEGREES * acos((double)((side1 * side1) + (side2 * side2) - (side * side)) / (2.0 * side1 * side2));
	angle2 = RADIAN_DEGREES * acos((double)((side2 * side2) + (side * side) - (side1 * side1)) / (2.0 * side * side2));

	// 3rd angle found using total degrees
	angle3 = TOTALDEGREES - (angle1 + angle2);

	printf("%f, %f, and %f", angle1, angle2, angle3);
}



char* triChecker(int side, int side1, int side2)
{
	char* result;

	// Will prepare a result

	if (side <= 0 || side1 <= 0 || side2 <= 0)
		result = "\nThis is not a triangle";

	else if (side == side1 && side == side2)
		result = "\nThis is an equilateral triangle";

	else if ((side == side1 && side != side2) || (side == side2 && side != side1) || (side1 == side2 && side != side1))
		result = "\nThis is an isosceles triangle";

	else
		result = "\nThis is a scalene triangle";

	// Print the result, and starts the program again
	if (result != "This is not a triangle")
	{
		printf("The angles do not belong to a triangle.");
		triAng(side, side1, side2);
	}

	else
		printf("%s", result);


	return result;
}







