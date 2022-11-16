typedef struct rectangle {
    double point1[2]; //point with min Y
    double point2[2]; //pont with max X
    double point3[2]; //point with max Y
    double point4[2]; //point with min X
}RECTANGLE;
RECTANGLE createRectangle(double pointsX[], double pointsY[]);
bool isRectangle(RECTANGLE);
double getArea(RECTANGLE);
double getPerimeter(RECTANGLE);