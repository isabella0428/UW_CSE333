#include <iostream>
#include "IntPair.h"

void Test(){
    int x,y;
    IntPair a = IntPair(1, 2);
    IntPair b = IntPair(3, 4);

    a.get(&x, &y);
    x += 1;
    y += 1;
    a.set(x, y);
    a.get(&x, &y);
    std::cout<<x<<" "<<y<<" "<<std::endl;

    b.get(&x, &y);
    x += 1;
    y += 1;
    b.set(x, y);
    b.get(&x, &y);
    std::cout << x << " " << y << " " << std::endl;
}

int main(int argc, char **argv){
    Test();
}