#include <stdint.h>

typedef struct Complex{
    int32_t real;
    int32_t imag;
}Complex, *Complex_ptr;

Complex_ptr add(Complex_ptr a, Complex_ptr b);
Complex_ptr subtract(Complex_ptr a, Complex_ptr b);
Complex_ptr multiply(Complex_ptr a, Complex_ptr b);
Complex_ptr divide(Complex_ptr a, Complex_ptr b);