#include "Vector.h"

Vector::Vector() {
    coordinate = new float[3];
    for(int i = 0; i < 3; ++i)
        coordinate[i] = 0;
}
Vector::Vector(const float x, const float y, const float z){
    coordinate = new float[3];
    coordinate[0] = x;
    coordinate[1] = y;
    coordinate[2] = z;
}
Vector::Vector(const Vector &v) {
    coordinate = new float[3];
    coordinate[0] = v.coordinate[0];
    coordinate[1] = v.coordinate[1];
    coordinate[2] = v.coordinate[2];
}

Vector Vector::operator=(const Vector &c){
    return Vector(c);
}

Vector Vector::operator+=(const Vector &v){
    coordinate[0] += v.coordinate[0];
    coordinate[1] += v.coordinate[1];
    coordinate[2] += v.coordinate[2];
    return *this;
}

Vector Vector::operator-=(const Vector &v) {
    coordinate[0] -= v.coordinate[0];
    coordinate[1] -= v.coordinate[1];
    coordinate[2] -= v.coordinate[2];
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

Vector operator*(Vector &a, double k){
    return Vector(a.coordinate[0] * k, a.coordinate[1] * k, a.coordinate[2] * k);
}

std::ostream &operator<<(std::ostream &out, const Vector &v){
    out<<"("<<v.coordinate[0]<<" "<<v.coordinate[1]<<" "<<v.coordinate[2]<<")"<<std::endl;
    return out;
}

float operator*(Vector &a, Vector &b){
    return a.coordinate[0]*b.coordinate[0]
    + a.coordinate[1]* b.coordinate[1]
    + a.coordinate[2]*b.coordinate[2];
}
