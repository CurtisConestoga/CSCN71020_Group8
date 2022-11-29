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
			for (int i = 0; i < 4; i++) {
				printf("Enter point no.%d: ", i + 1);
				scanf("%lf %lf", &pointsX[i], &pointsY[i]);
			}

			RECTANGLE rectangle = createRectangle(pointsX, pointsY);
			if (isRectangle(rectangle))
				printf("These points make a rectangle, the area is %lf \n", getArea(rectangle));
			else
				printf("These points do not make a rectangle. ");
			printf("The perimeter is: %lf", getPerimeter(rectangle));
			break;
		case 1:
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			if (result == "Not a triangle") {
				printf_s("%s\n", result);
			}
			else {
				printf_s("%s\n", result);
				double angles = triAng(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			}
				
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