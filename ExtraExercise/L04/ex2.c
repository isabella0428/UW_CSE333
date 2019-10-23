#include <stdio.h>
#include <stdlib.h>

typedef struct complex_st
{
    double real; // real component
    double imag; // imaginary component
} Complex;

typedef struct complex_set_st
{
    double num_points_in_set;
    Complex *points; // an array of Complex
} ComplexSet;

/* <p>AllocSet() needs to use malloc twice: once to allocate a new ComplexSet
 and once to allocate the “points” field inside it*/
ComplexSet *AllocSet(Complex c_arr[], int size){
    ComplexSet *retAllocSet = (ComplexSet *)malloc(sizeof(ComplexSet));
    if(retAllocSet == NULL){
        return NULL;
    }
    retAllocSet->num_points_in_set = size;
    retAllocSet->points = (Complex *)malloc(size*(sizeof(Complex)));
    if(retAllocSet->points == NULL)
        return NULL;
    for(int i = 0; i < size; ++i){
        retAllocSet->points[i] = c_arr[i];
    }
    return retAllocSet;
}

/* <p> FreeSet() needs to use free twice */
void FreeSet(ComplexSet *set){
    free(set->points);
    free(set);
}

int main(int argc, char **argv){
    Complex a = {1, 2};
    Complex b = {2, 3};
    Complex c_arr[] = {a, b};
    ComplexSet *set = AllocSet(c_arr, 2);
    for(int i = 0; i < 2; ++i){
        printf("real: %f imagine: %f", ((set->points)[i]).real, (set->points[i]).imag);
    }
}



