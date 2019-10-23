#include "ex1.h"
#include <iostream>
using namespace std;

int main(int argc, char ** argv){
    Point a = Point(1, 2, 3);
    Point b = Point(3, 4, 5);
    cout<<distance(a, b)<<endl;
    cout <<innerProduct(a, b) << endl;
    cout<<(a+b).getX()<<" " << (a+b).getY()<<" "<<(a+b).getZ()<<endl;
}