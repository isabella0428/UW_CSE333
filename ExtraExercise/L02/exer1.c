#include <stdint.h>
#include <stdio.h>

void reverseArray(uint32_t src[], int length){
    uint32_t tmp;
    for(int i = 0; i < length / 2; ++i){
        tmp = src[i];
        src[i] = src[length - 1 - i];
        src[length - 1 - i] = tmp;
    }
}

/*<p> Reverse the elements of the given array */
int main(int argc, char **argv){
    uint32_t src[] = {0,1,2,3,4,5,6,7,8};
    reverseArray(src, 9);
    for(int i = 0; i < 9; ++i){
        printf("%d\n", src[i]);
    }
}