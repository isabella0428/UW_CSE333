#include "Vector.h"

Vector::Vector() : x_(0), y_(0), z_(0) {}
Vector::Vector(float x, float y, float z) : x_(x), y_(y), z_(z) {}
Vector::Vector(Vector &v) : x_(v.x_), y_(v.y_), z_(v.z_) {}

Vector Vector::operator=(Vector &c){
    x_ = c.x_;
    y_ = c.y_;
    z_ = c.z_;
    return *this;
}

Vector Vector::operator+=(Vector &c){
    x_ += c.x_;
    y_ += c.y_;
    z_ += c.z_;
    return *this;
}

Vector Vector::operator-=(Vector &c){
    x_ -= c.x_;
    y_ -= c.y_;
    z_ -= c.z_;
    return *this;
}

Vector operator+(Vector a, Vector b){
    Vector ret;
    ret += a;
    ret += b;
    return ret;
}

Vector operator-(Vector a, Vector b){
    Vector ret;
    ret += a;
    ret -= b;
    return ret;
}

std::ostream &operator<<(std::ostream &out, const Vector &v){
    out<<"("<<v.x_<<" "<<v.y_<<" "<<v.z_<<")"<<std::endl;
    return out;
}