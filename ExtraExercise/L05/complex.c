#include "complex.h"
#include <stdint.h>
#include <stdlib.h>

/* Implement a Complex number module */
Complex_ptr add(Complex_ptr a, Complex_ptr b){
    Complex_ptr n = (Complex_ptr)malloc(sizeof(Complex));
    n->real = a->real + b->real;
    n->imag = a->imag + b->imag;
    return n;
}

Complex_ptr subtract(Complex_ptr a, Complex_ptr b)
{
    Complex_ptr n = (Complex_ptr)malloc(sizeof(Complex));
    n->real = a->real - b->real;
    n->imag = a->imag - b->imag;
    return n;
}

Complex_ptr multiply(Complex_ptr a, Complex_ptr b)
{
    Complex_ptr n = (Complex_ptr)malloc(sizeof(Complex));
    n->real = a->real * b->real - a->imag * b->imag;
    n->imag = a->imag * b->real + a->real * b->imag;
    return n;
}
