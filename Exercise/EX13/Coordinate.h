#ifndef _Coordinate_
#define _Coordinate_

#include <string>
using namespace std;

class Coordinate {
    public:
        double a_, b_;
        Coordinate(double a, double b) : a_(a), b_(b) {}
        virtual void toString(char * x_string) = 0;
};

#endif