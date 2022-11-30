#pragma once
#if __cplusplus
extern "C" {
#endif
/*CSCN7102022F - Group Project - rectangle.h
*
* This module contains the declarations of the functions related to the rectangle implementation of the program.
*
*/

typedef struct rectangle {
    double point1[2];
    double point2[2];
    double point3[2];
    double point4[2];

    double L12;
    double L23;
    double L34;
    double L41;

}RECTANGLE;

/*
* Function: createRectangle()
* ------------------------
* This function takes two arrays that create a pairing of (X,Y) coordinates and creates a rectangle struct that has the properties of corners and line lengths and returns it.
*
* Params: double pointsX[], pointsY[]
* Return: RECTANGLE newRectangle
*/
RECTANGLE createRectangle(double pointsX[], double pointsY[]);

/*
* Function: isRectangle()
* ------------------------
* This function takes a rectangle struct as a parameter and verifies if it is a rectangle and returns a boolean result.
*
* Params: RECTANGLE rectangleToCheck
* Return: bool result
*/
bool isRectangle(RECTANGLE);

/*
* Function: getArea()
* ------------------------
* This function takes a rectangle struct as a parameter and returns the area of the rectangle.
*
* Params: RECTANGLE rectangleToGetAreaFor
* Return: double area
*/
double getArea(RECTANGLE);

/*
* Function: getPerimeter()
* ------------------------
* This function takes a rectangle struct as a parameter and returns the perimeter of the rectangle.
*
* Params: RECTANGLE rectangleToGetPerimeterFor
* Return: double perimeter
*/
double getPerimeter(RECTANGLE);

#if __cplusplus
}
#endif

