#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

template<typename T>
T ReadValue(istream & in){
    if(in.good()){
        T a;
        in>>a;
        return a;
    }
    else{
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char ** argv){
    vector<double> vec;

    cout<<"Please input 10 doubles:"<<endl;
    for(int i = 0; i < 10; ++i){
        vec.push_back(ReadValue<double>(cin));
    }
    sort(vec.begin(), vec.end());

    cout<<"Doubles after sorted:"<<endl;
    for(vector<double>::iterator it = vec.begin(); it < vec.end(); ++it){
        cout<<*it<<" ";
    }
}
