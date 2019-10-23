#include <iostream>
#include <vector>
#include <memory>
#include "shape.h"

typedef shared_ptr<Shape> shapePtr;

int main(int argc, char **argv){
    vector<shared_ptr<Shape>> ::iterator iterator;
    vector<shared_ptr<Shape> > vector;
    shared_ptr<Shape> circle = make_shared<Circle>(5, 4, 3);
    vector.push_back(circle);

    shared_ptr<Shape> triangle = make_shared<Triangle>(1, 2, 3, 8, 6, 7);
    vector.push_back(triangle);

    shared_ptr<Shape> square = make_shared<Square>(1, 2, 3, 4);
    vector.push_back(square);

    for (iterator = vector.begin(); iterator != vector.end(); ++iterator)
    {
        (*iterator)->Print();
    }
}