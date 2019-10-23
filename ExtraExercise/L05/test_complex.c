#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "complex.h"

int main(int argc, char **argv){
    Complex_ptr a = (Complex_ptr)malloc(sizeof(Complex));
    Complex_ptr b = (Complex_ptr)malloc(sizeof(Complex));
    a->real = 1;
    a->imag = 2;
    b->real = 3;
    b->imag = 4;
    printf("a add b is %d + %di\n", add(a, b)->real, add(a, b)->imag);
    printf("a subtract b is %d + %di\n", subtract(a, b)->real, subtract(a, b)->imag);
    printf("a multiply b is %d + %di\n", multiply(a, b)->real, multiply(a, b)->imag);
}