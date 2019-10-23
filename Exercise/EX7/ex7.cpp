#include <iostream>
#include <cmath>
#include <set>
using namespace std;

/** <ul>Write a C++ program that:
  *      <li>Prompts the user for a positive integer
  *      <li>Prints out all integers that are factors of that integer; 
  */
int main(int argc, char **argv)
{
    int a, b;
    set<int>::iterator itr;
    set<int> mySet;
    cout << "Please input an integer" << endl;
    cin >> a;
    for(int i = 1; i <= sqrt(a); ++i)
    {
        if(a % i == 0){
            mySet.insert(i);
            mySet.insert(a / i);
        }
    }
    for(itr = mySet.begin(); itr != mySet.end(); ++itr){
        cout<<*itr<<' ';
    }
    return 0;
}