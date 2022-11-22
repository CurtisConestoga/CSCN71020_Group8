#pragma once
#if __cplusplus
extern "C" {
#endif

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
RECTANGLE createRectangle(double pointsX[], double pointsY[]);
bool isRectangle(RECTANGLE);
double getArea(RECTANGLE);
double getPerimeter(RECTANGLE);

#if __cplusplus
}
#endif

