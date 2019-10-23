#include "Vector.h"
using namespace std;

int main(int argc, char **argv){
    Vector a;
    cout<<"a is "<< a;

    Vector b(1.0f, 2.0f, 3.0f);
    cout<<"b is "<< b;

    Vector c(b);
    cout<<"c is "<<c;

    cout<<(a += b);
    cout<<(a -= b);

    cout<<(a + c);
    cout<<(b - c);

    cout<<"b * c is " << b * c<<endl;
    cout<< "b * 3 is "<< b * 3.0;
}