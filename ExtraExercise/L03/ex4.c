#include <stdio.h>

/* Function invoker */
void functionInvoker(void (*op)(int n), int N){
    (*op)(N);
}

void printInteger(int N){
    printf("%d\n", N);
}


int main(int argc, char **argv){
    void (*op)(int n);
    op = printInteger;
    functionInvoker(op, 5);
}