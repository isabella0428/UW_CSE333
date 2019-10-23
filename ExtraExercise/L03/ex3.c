#include <stdio.h>
#include <stdlib.h>

/* <ul>Function returnPointerArray:
        <li>Arguments: [1] an array of ints and [2] an array length
        <li>Malloc’s an int* array of the same element length 
        <li>Initializes each element of the newly-allocated array to point to the corresponding element of the passed-in array
        <li>Returns a pointer to the newly-allocated array
*/


int** returnPointerArray(int a[], int length){
    int **b = malloc(length * sizeof(int*));
    for(int i = 0; i < length; ++i){
        b[i] = &a[i];
    }
    return b;
}

int main(int argc, char **argv){
    int a[] = {1, 2, 3};
    int **b = returnPointerArray(a, 3);
    for(int i = 0; i < 3; ++i){
        printf("%d\n", *b[i]);
    }
    free(b);
}