#include <stdio.h>

/** <p> This file is intended to test whether double and int arrays in c 
 *  are passed-by-value or passed-by-reference
 */

void testDouble(double a){
    a++;
    return;
}

void testArray(int a[]){
    int b[] = {1, 2};
    a = b;
    return;
}
int main(int argc, char *argv[]){
    double a = 1;
    int b[] = {3,4};
    testDouble(a);
    testArray(b);
    printf("double: %s\n", a == 1 ? "pass-by-value" : "pass-by-reference");
    printf("array of ints: %s\n", b[0] == 3 ? "pass-by-value" : "pass-by-reference");
}