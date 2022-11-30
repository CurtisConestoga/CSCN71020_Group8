#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "rectangle.h"

/*CSCN7102022F - Group Project - rectangle.c
*
* This module contains the definitions of the functions related to the rectangle implementation of the program.
*
*/
RECTANGLE createRectangle(double pointsX[], double PointsY[]) {
    RECTANGLE newRectangle;
    //set X points
    newRectangle.point1[0] = pointsX[0];
    newRectangle.point2[0] = pointsX[1];
    newRectangle.point3[0] = pointsX[2];
    newRectangle.point4[0] = pointsX[3];
    //set Y points
    newRectangle.point1[1] = PointsY[0];
    newRectangle.point2[1] = PointsY[1];
    newRectangle.point3[1] = PointsY[2];
    newRectangle.point4[1] = PointsY[3];

    //do line lengths
    newRectangle.L12 = sqrt(pow(newRectangle.point2[0] - newRectangle.point1[0], 2) + pow(newRectangle.point2[1] - newRectangle.point1[1], 2));
    newRectangle.L23 = sqrt(pow(newRectangle.point3[0] - newRectangle.point2[0], 2) + pow(newRectangle.point3[1] - newRectangle.point2[1], 2));
    newRectangle.L34 = sqrt(pow(newRectangle.point4[0] - newRectangle.point3[0], 2) + pow(newRectangle.point4[1] - newRectangle.point3[1], 2));
    newRectangle.L41 = sqrt(pow(newRectangle.point4[0] - newRectangle.point1[0], 2) + pow(newRectangle.point4[1] - newRectangle.point1[1], 2));

    return newRectangle;
}

bool isRectangle(RECTANGLE rectangle) {
    if (rectangle.L12 == rectangle.L34 && rectangle.L41 == rectangle.L23) {
        if (rectangle.L12 != rectangle.L41)
            return true;
        else
            return false;
    }
    else {
        return false;
    }
}
double getArea(RECTANGLE rectangle) {
    return floorf((rectangle.L34 * rectangle.L41)*100) / 100;
}

double getPerimeter(RECTANGLE rectangle) {
    return floorf((rectangle.L12 + rectangle.L23 + rectangle.L34 + rectangle.L41)*100) /100;
}