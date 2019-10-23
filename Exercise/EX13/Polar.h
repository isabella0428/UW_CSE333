#ifndef _Polar_
#define _Polar_

#include <iostream>
#include <string>
#include <cmath>
#include <stdarg.h>
#include "Coordinate.h"
using namespace std;

class Polar : public Coordinate {
    public:
        Polar(double x, double y): Coordinate(x, y) {}

        void toString(char * p_string) override {
            sprintf(p_string, "Polar: radius: %f angle: %f", a_, b_);
        }

        double distance(Polar & polar) {
            return sqrt(this->a_ * this->a_ + polar.a_ * polar.a_
                 - 2 * this->a_ * polar.a_ * cos(this->b_ - polar.b_));
        }
};

#endif