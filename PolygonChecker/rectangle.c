#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "rectangle.h"

//this function takes 2 arrays of type double which are coordinates on a cartesian plane, finds the index of the points with the maximum and minimum values of X and Y
//then finds the correspending points and creates a rectangle using them.
RECTANGLE createRectangle(double pointsX[], double pointsY[]) {
   
    double maxY = pointsY[0], maxX = pointsX[0];
    double minY = pointsY[0], minX = pointsX[0];
    double indexXMax = 0, indexYMax = 0;
    double indexXMin = 0, indexYMin = 0;
    bool upright = false;
    //check if rectangle is upright
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (pointsX[i] == pointsX[j])
                upright = true;  
        }
    }
    RECTANGLE newRectangle;
    if (upright) {
        RECTANGLE rect2;
        int skipIndex = 0;
        printf("upright");
        //iterate thru from left to right
        //this first one breaks and returns 1 and 4
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                if (pointsX[i] == pointsX[j]) {
                    if (pointsY[i] > pointsY[j]) {
                        rect2.point1[0] = pointsX[j], rect2.point1[1] = pointsY[j];
                        rect2.point4[0] = pointsX[i], rect2.point4[1] = pointsY[i];
                    }
                    else {
                        rect2.point1[0] = pointsX[i], rect2.point1[1] = pointsY[i];
                        rect2.point4[0] = pointsX[j], rect2.point4[1] = pointsY[j]; 
                    }
                    
                } 
            }
            break;
        }
        //this one returns 2,3
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                if (pointsX[i] == pointsX[j]) {
                    if (pointsY[i] > pointsY[j]) {
                        rect2.point2[0] = pointsX[j], rect2.point2[1] = pointsY[j];
                        rect2.point3[0] = pointsX[i], rect2.point3[1] = pointsY[i];
                    }
                    else {
                        rect2.point2[0] = pointsX[i], rect2.point2[1] = pointsY[i];
                        rect2.point3[0] = pointsX[j], rect2.point3[1] = pointsY[j];
                    }

                }
            }
        }
       // printf("point 1: (%lf,%lf) point 2: (% lf, % lf) point 3: (% lf, % lf) point 4: (%lf,%lf)", rect2.point1[0], rect2.point1[1], rect2.point2[0], rect2.point2[1], rect2.point3[0], rect2.point3[1], rect2.point4[0], rect2.point4[1]);
        return rect2;
    }else {
        //find the indexs of the points that contain the max and min X and Y values
        for (int i = 0; i < 4; i++) {
            if (pointsX[i] > maxX) {
                maxX = pointsX[i];
                indexXMax = (double)i;
            }
            if (pointsX[i] < minX) {
                minX = pointsX[i];
                indexXMin = (double)i;
            }
            if (pointsY[i] < minY) {
                minY = pointsY[i];
                indexYMin = (double)i;
            }
            if (pointsY[i] > maxY) {
                maxY = pointsY[i];
                indexYMax = (double)i;
            }
        }
        //find the max and min x and Y values
        double pointMaxY[2] = { pointsX[(int)indexYMax], pointsY[(int)indexYMax] };
        double pointMinY[2] = { pointsX[(int)indexYMin], pointsY[(int)indexYMin] };
        double pointMaxX[2] = { pointsX[(int)indexXMax], pointsY[(int)indexXMax] };
        double pointMinX[2] = { pointsX[(int)indexXMin], pointsY[(int)indexXMin] };
        //set the ordered points to the values found
        newRectangle.point1[0] = pointMinY[0], newRectangle.point1[1] = pointMinY[1];
        newRectangle.point2[0] = pointMaxX[0], newRectangle.point2[1] = pointMaxX[1];
        newRectangle.point3[0] = pointMaxY[0], newRectangle.point3[1] = pointMaxY[1];
        newRectangle.point4[0] = pointMinX[0], newRectangle.point4[1] = pointMinX[1];
        /*printf("max X point: (%lf , %lf) min X point: (%lf , %lf)  max Y point: (%lf , %lf) min Y point: (%lf , %lf) \n",
            pointMaxX[0], pointMaxX[1], pointMinX[0], pointMinX[1],
            pointMaxY[0], pointMaxY[1], pointMinY[0], pointMinY[1]);*/
        return newRectangle;
    }
   

   
    
   
}
//This function compares the diagonals of the given four-cornered shape, 
//if the diaganols are equal to eachother, the shape is a rectangle and will return true; if not it will return false
bool isRectangle(RECTANGLE rectangle) {
    /*double diagX = sqrt(pow(rectangle.point2[0] - rectangle.point4[0], 2) + pow(rectangle.point2[1] - rectangle.point4[1], 2));
    double diagY = sqrt(pow(rectangle.point3[0] - rectangle.point1[0], 2) + pow(rectangle.point3[1] - rectangle.point1[1], 2));
    printf("diag of X: %lf diag of Y: %lf", diagX, diagY);*/
    double LP12 = sqrt(pow(rectangle.point2[0] - rectangle.point1[0], 2) + pow(rectangle.point2[1] - rectangle.point1[1],2)); //AB
    double LP34 = sqrt(pow(rectangle.point4[0] - rectangle.point3[0], 2) + pow(rectangle.point4[1] - rectangle.point3[1], 2));//DC
    double LP14 = sqrt(pow(rectangle.point4[0] - rectangle.point1[0], 2) + pow(rectangle.point4[1] - rectangle.point1[1], 2)); //AD
    double LP23 = sqrt(pow(rectangle.point3[0] - rectangle.point2[0], 2) + pow(rectangle.point3[1] - rectangle.point2[1], 2)); //BC
    //printf("opposites are %lf and %lf then %lf and %lf", LP12, LP34, LP14, LP23);
    if (LP12 == LP34 && LP14 == LP23) {
        if (LP12 != LP14)
            return true;
        else 
            return false;
    }
   // printf("opposite widths are: %lf and %lf opposite lengths are: %lf and %lf", LP14, LP23, LP34, LP12);
}

double getArea(RECTANGLE rectangle) {
    double LP34 = sqrt(pow(rectangle.point4[0] - rectangle.point3[0], 2) + pow(rectangle.point4[1] - rectangle.point3[1], 2));//DC
    double LP14 = sqrt(pow(rectangle.point4[0] - rectangle.point1[0], 2) + pow(rectangle.point4[1] - rectangle.point1[1], 2)); //AD
    return LP34 * LP14;
}

double getPerimeter(RECTANGLE rectangle) {
    double LP34 = sqrt(pow(rectangle.point4[0] - rectangle.point3[0], 2) + pow(rectangle.point4[1] - rectangle.point3[1], 2));//DC
    double LP14 = sqrt(pow(rectangle.point4[0] - rectangle.point1[0], 2) + pow(rectangle.point4[1] - rectangle.point1[1], 2)); //AD

    return (2 * LP34) + (2 * LP14);
}