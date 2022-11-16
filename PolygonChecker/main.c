#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include "main.h"
#include "triangleSolver.h"
#include "rectangle.h"

int side = 0;

int main() {
	printf("Hello");
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 2:
			printf("Rectangle selected.\n");
			double pointsX[4];
			double pointsY[4];
			//get points from user
			for (int i = 0; i < 4; i++) {
				printf("enter a point %d/4: \n", i + 1);
				scanf("%lf %lf", &pointsX[i], &pointsY[i]);
			}
			RECTANGLE rectangle = createRectangle(pointsX, pointsY);
			if (isRectangle(rectangle))
				printf("The points make a rectangle \nThe area of the rectangle is: %lf \n", getArea(rectangle));
			else
				printf("The shape is not a rectangle \n");

			printf("The perimeter is: %lf", getPerimeter(rectangle));
			break;
		case 1:
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			//float triangleAngles[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			//printf_s("! %d\n", triangleSidesPtr[0]);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result);
			//triangleInsideAngle(triangleSidesPtr, triangleAngles);
			break;
		case 0:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("2. Rectangle\n");
	printf_s("1. Triangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("Enter number: ");
	scanf_s("%1o", &shapeChoice);

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%d", &triangleSides[i]);
	}
	return triangleSides;
}