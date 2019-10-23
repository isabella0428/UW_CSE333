#include <stdio.h>

typedef struct Points{
    float x, y;
}Point;

typedef struct Rectangles{
    float x1, y1;   //bottom left point
    float x2, y2;   //top right point
}Rectangle;

/* Computes and returns the area of a Rectangle*/
float Rectangle_Area(Rectangle r){
    return (r.y2 - r.y1) * (r.x2 - r.x1);
}

/* Tests whether a Point is inside of a Rectangle */
int isPointInRectangle(Point p, Rectangle r){
    return (p.x > r.x1) && (p.x < r.x2) && (p.y > r.y1) && (p.y < r.y2);
}

int main(int argc, char **argv){
    Point p = {2, 3};
    Rectangle r = {1, 5, 3, 7};
    printf("Rectangle's area is : %f.\n", Rectangle_Area(r));
    printf("Point %s in the Rectange.\n", isPointInRectangle(p, r)?"is":"is not");
}