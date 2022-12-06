#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "rectangle.h"


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


RECTANGLE checkRectangle(double pointsX[], double PointsY[]) {

    //Actual rectangle that will be returned
    RECTANGLE r;
    //Temporary place holder for first inputs recieved 
    RECTANGLE temp;
    double result0, result1, result2 = 0;
    double highest;


    //set X points
    temp.point1[0] = pointsX[0];
    temp.point2[0] = pointsX[1];
    temp.point3[0] = pointsX[2];
    temp.point4[0] = pointsX[3];
    //set Y points
    temp.point1[1] = PointsY[0];
    temp.point2[1] = PointsY[1];
    temp.point3[1] = PointsY[2];
    temp.point4[1] = PointsY[3];



    //Will assign whatever the first coordinates recieved first as the first vertex
    r.point1[0] = temp.point1[0];
    r.point1[1] = temp.point1[1];


    //These equations are used to calculate the point that is the farthest one away
    //from point 1. That point would be the opposite one of it then it would be a matter
    //of assigning the remaining variables
    result0 = sqrt(pow(temp.point2[0] - temp.point1[0], 2) + pow(temp.point2[1] - temp.point1[1], 2));
    result1 = sqrt(pow(temp.point3[0] - temp.point1[0], 2) + pow(temp.point3[1] - temp.point1[1], 2));
    result2 = sqrt(pow(temp.point4[0] - temp.point1[0], 2) + pow(temp.point4[1] - temp.point1[1], 2));



    printf("\nUnorganized points ");
    printf("\npoint 1 is %lf, %lf", temp.point1[0], temp.point1[1]);
    printf("\npoint 2 is %lf, %lf", temp.point2[0], temp.point2[1]);
    printf("\npoint 3 is %lf, %lf", temp.point3[0], temp.point3[1]);
    printf("\npoint 4 is %lf, %lf", temp.point4[0], temp.point4[1]);



    //This will mean that the distance between point 1 and point 2 is the highest making point 2
    // the point that is opposite to it thus making it the third corner 
    if (result0 > result1 && result0 > result2)
    {
        r.point3[0] = temp.point2[0];
        r.point3[1] = temp.point2[1];

        r.point2[0] = temp.point3[0];
        r.point2[1] = temp.point3[1];

        r.point4[0] = temp.point4[0];
        r.point4[1] = temp.point4[1];
    }

    else if ((result1 > result0 && result1 > result2))
    {
        r.point3[0] = temp.point3[0];
        r.point3[1] = temp.point3[1];

        r.point2[0] = temp.point2[0];
        r.point2[1] = temp.point2[1];

        r.point4[0] = temp.point4[0];
        r.point4[1] = temp.point4[1];
    }

    else if (result2 > result1 && result2 > result0)
    {
        r.point3[0] = temp.point4[0];
        r.point3[1] = temp.point4[1];

        r.point2[0] = temp.point3[0];
        r.point2[1] = temp.point3[1];

        r.point4[0] = temp.point2[0];
        r.point4[1] = temp.point2[1];
    }


    r.L12 = sqrt(pow(r.point2[0] - r.point1[0], 2) + pow(r.point2[1] - r.point1[1], 2));
    r.L23 = sqrt(pow(r.point3[0] - r.point2[0], 2) + pow(r.point3[1] - r.point2[1], 2));
    r.L34 = sqrt(pow(r.point4[0] - r.point3[0], 2) + pow(r.point4[1] - r.point3[1], 2));
    r.L41 = sqrt(pow(r.point4[0] - r.point1[0], 2) + pow(r.point4[1] - r.point1[1], 2));

    return r;

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
    return rectangle.L34 * rectangle.L41;
}

double getPerimeter(RECTANGLE rectangle) {
    return rectangle.L12 + rectangle.L23 + rectangle.L34 + rectangle.L41;
}