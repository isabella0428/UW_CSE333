#include "Cartesian.h"
#include "Polar.h"
#include "Coordinate.h"

int main(int argc, char **argv) {
    Cartasian cartasian1(1, 3), cartasian2(4, 7);
    char c_string[200];
    cartasian1.toString(c_string);
    cout<< c_string;
    cout << " to ";
    cartasian2.toString(c_string);
    cout<<" is " << cartasian1.distance(cartasian2) << endl;

    Polar polar1(3, 30), polar2(4, 70);
    polar1.toString(c_string);
    cout << c_string;
    cout << " to ";
    polar2.toString(c_string);
    cout << " is " << polar1.distance(polar2) << endl;
}