#include <iostream>

class Vector{
    public:
        Vector();
        Vector(float x, float y, float z);
        Vector(Vector & v);
        Vector operator=(Vector &c);
        Vector operator+=(Vector &c);
        Vector operator-=(Vector &c);
        ~Vector(){}

    private:
        float x_, y_, z_;

    friend std::ostream &operator<<(std::ostream &out, const Vector &v);
};

Vector operator+(Vector a, Vector b);
Vector operator-(Vector a, Vector b);
std::ostream &operator<<(std::ostream &out, const Vector &v);