#include "Tracer.h"
#include <cstdio>
#include <vector>
#include <list>
using namespace std;

int compare(const list<Tracer> &a, const list<Tracer> &b){
    if(*a.begin() < *b.begin())
        return 1;
    return -1;
}

int main(int argc, char **argv){
    Tracer a, b, c, d, e, f, g, h, i;
    list<Tracer> lst1, lst2, lst3;
    vector< list<Tracer> > vec;

    lst1.push_back(a);
    lst1.push_back(b);
    lst1.push_back(c);

    lst2.push_back(d);
    lst2.push_back(e);
    lst2.push_back(f);

    lst3.push_back(g);
    lst3.push_back(h);
    lst3.push_back(i);

    vec.push_back(lst1);
    vec.push_back(lst2);
    vec.push_back(lst3);

    sort(vec.begin(), vec.end(), compare);
}  