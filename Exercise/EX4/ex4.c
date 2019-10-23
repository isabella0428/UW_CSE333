#include <stdint.h>
#include <stdio.h>
#include "Vector.h"

int main(int argc, char *argv[])
{
    uint32_t i;
    element_t old;
    int *x;
    vector_t v = VectorCreate(4);

    if (v == NULL)
        return EXIT_FAILURE;

    int y;

    for (i = 0; i < N; ++i)
    { // Place some elements in the vector.
        x = (int *)malloc(sizeof(int));
        *x = i;
        VectorSet(v, i, x, &old);
        y = *((int *)v->arry[i]);
    }
    PrintIntVector(v);

    return EXIT_SUCCESS;
}