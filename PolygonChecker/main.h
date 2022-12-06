#pragma once
/*CSCN7102022F - Group Project - main.h
*
* This module contains declarations of the functions used in the main.c file of the program.
*
*/

/*
* Function: printWelcome()
* ------------------------
* This function prints a welcome message to the command line interface.
*
* Params: void
* Return: void
*/
void printWelcome();

/*
* Function: printShapeMenu()
* ------------------------
* This function prints a menu of shapes for the user to choose from to the command line interface.
*
* Params: void
* Return: int optionSelected
*/
int printShapeMenu();

/*
* Function: getTriangleSides()
* ------------------------
* This function takes a pointer to an array as input, then retrieves input from the user to store in the array to be used for calculations related to the triangle features.
*
* Params: int* triangleSidesPtr
* Return: int* triangleSidesPtr
*/
int* getTriangleSides(int* triangleSides);