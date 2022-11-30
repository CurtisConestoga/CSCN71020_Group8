#pragma once
/*CSCN7102022F - Group Project - triangleSolver.h
*
* This module contains declarations of the functions to be used to perform operations related to triangles.
*
*/

/*
* Function: analyzeTriangle()
* ------------------------
* This function takes three integers as parameters that are to be side lengths of a triangle retrieved by the user.
* This function returns a string that describes what kind of triangle the side lengths make, or if the side lengths do not result in a triangle.
*
* Params: int sideLength1, sideLength2, sideLength3
* Return: char* result
*/
char* analyzeTriangle(int side1, int side2, int side3);

/*
* Function: triAng()
* ------------------------
* This function takes three integers as parameters that are to be side lengths of a triangle retrieved by the user.
* This function prints the inside angles of the triangle calculated by the side lengths retrived by the user.
* This function returns the sum of the inside angle degrees.
*
* Params: int sideLength1, sideLength2, sideLength3
* Return: double result
*/
double triAng(int side, int side1, int side2);
