#ifndef _Cartesian_
#define _Cartesian_

#include <string>
#include <iostream>
#include <cmath>
#include <stdarg.h>
#include "Coordinate.h"
using namespace std;

class Cartasian : public Coordinate {
public:
    double distance(Coordinate &coordinate)
    {
        return sqrt(pow((this->a_ - coordinate.a_), 2) + pow((this->b_ - coordinate.b_), 2));
    }

    Cartasian(double x, double y) : Coordinate(x, y) {}

    void toString(char * c_string) override{
        sprintf(c_string, "Cartasian: x: %f y: %f", a_, b_);
    }
};

#endif