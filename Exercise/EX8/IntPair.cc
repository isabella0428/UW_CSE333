#include "IntPair.h"

IntPair::IntPair(int x, int y):x_(x), y_(y){}

void IntPair::get(int *x, int *y) const{
    *x = x_;
    *y = y_;
}

void IntPair::set(const int const &x, const int const &y){
    x_ = x;
    y_ = y;
}