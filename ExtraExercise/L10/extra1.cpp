#include <iostream>
#include <iomanip>
using namespace std;

/**   <ul>Write a C++ program that uses stream to:
  *       <li>Prompt the user to type 5 floats
  *       <li>Prints them out in opposite order with 4 digits of precision
*/

int main(int argc, char **argv){
    double a[5];
    for(int i = 0; i < 5; ++i){
        cout<<"Please input the "<<i + 1<<"th double:"<<endl;
        cin>>a[i];
    }
    for(int i = 4; i >=0 ;--i){
        cout<<setw(4)<<setfill('0')<<a[i]<<endl;
    }
    return 0;
}