#include <stdio.h>

/** <p> Test whether your computer is big-endian or little endian */

int main(int argc, char **argv){
    int a[] = {1, 2, 3};
    char *p = (char *)a + 3;
    printf("My computer is %s", *p == 1 ? "big endian." : "little endian.");
}