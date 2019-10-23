#include "ex1.h"
#include <cmath>

Point::Point(const double x, const double y, const double z):x_(x), y_(y), z_(z){}

void Point::mutateValue(const double x, const double y, const double z){
    this->x_ = x;
    this->y_ = y;
    this->z_ = z;
}

double innerProduct(Point a, Point b) {
    return a.getX() *  b.getX()+ a.getY()* b.getY() + a.getZ() * b.getZ(); 
}

double distance( Point a, Point b){
    return sqrt((a.getX() - b.getX()) * (a.getX() - b.getX())
     + (a.getY() * b.getY()) * (a.getY() * b.getY()) 
     + (a.getZ() * b.getZ()) * (a.getZ() * b.getZ()));
}

Point operator +(Point a, Point b){
    return Point(a.x_ + b.x_, a.y_ + b.y_, a.z_ + b.z_);
}