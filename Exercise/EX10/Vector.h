#include <iostream>

class Vector{
    public:
        Vector();
        Vector(const float x, const float y, const float z);
        Vector(const Vector & v);
        Vector operator=(const Vector &c);
        Vector operator+=(const Vector &c);
        Vector operator-=(const Vector &c);
        ~Vector(){delete[] coordinate;}

    private:
        float *coordinate;

    friend std::ostream &operator<<(std::ostream &out, const Vector &v);
    friend float operator*(Vector &a, Vector &b);
    friend Vector operator*(Vector &a, double k);
};

Vector operator+(Vector a, Vector b);
Vector operator-(Vector a, Vector b);
Vector operator*(Vector &a, double k);
float operator*(Vector &a, Vector &b);
std::ostream &operator<<(std::ostream &out, const Vector &v);