#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "Vector.h"

//okay
vector_t VectorCreate(size_t n)
{
    vector_t v = (vector_t)malloc(sizeof(struct vector_t));
    v->arry = (element_t *)malloc(n * sizeof(element_t));
    v->length = n;
    if (v == NULL || v->arry == NULL)
        return NULL;
    return v;
}

void VectorFree(vector_t v)
{
    assert(v != NULL);
    free(v->arry);
    free(v);
}

//okay
bool VectorSet(vector_t v, uint32_t index, element_t e, element_t *prev)
{
    assert(v != NULL);
    *prev = NULL;

    if (index >= v->length)
    {
        size_t newLength = index + 1;

        v->arry = ResizeArray(v->arry, v->length, newLength);
        v->length = newLength;
    }
    else
    {
        *prev = v->arry[index];
    }

    v->arry[index] = e;

    return true;
}

element_t VectorGet(vector_t v, uint32_t index)
{
    assert(v != NULL);
    return v->arry[index];
}

size_t VectorLength(vector_t v)
{
    assert(v != NULL);
    return v->length;
}

//okay
static element_t *ResizeArray(element_t *arry, size_t oldLen, size_t newLen)
{
    uint32_t i;
    size_t copyLen = oldLen;
    element_t *newArry;

    assert(arry != NULL);

    newArry = (element_t *)malloc(newLen * sizeof(element_t));

    if (newArry == NULL)
        return NULL; // malloc error!!!

    // Copy elements to new array
    for (i = 0; i < copyLen; ++i)
        newArry[i] = arry[i];

    // Null initialize rest of new array.
    for (i = copyLen; i < newLen; ++i)
        newArry[i] = NULL;

    return newArry;
}

void PrintIntVector(vector_t v)
{
    uint32_t i;
    size_t length;

    assert(v != NULL);

    length = VectorLength(v);
    int x;
    if (length > 0)
    {
        x = *((int *)VectorGet(v, 0));
        printf("[%d", *((int *)VectorGet(v, 0)));
        for (i = 1; i < VectorLength(v); ++i)
            printf(",%d", *((int *)VectorGet(v, i)));
        printf("]\n");
    }
    free(v);
}
