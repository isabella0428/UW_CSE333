#include <stdio.h>
#include <stdint.h>

/** <p> This function is meant to copy src array's elements 
 * into dest array and sort them in ascending order
 */
void CopyAndSort(int32_t src[], int32_t dest[], uint32_t length){
    int32_t temp;
    int loc;

    /* copy the contents of src to array */
    for(int i = 0; i < length; ++i){
        dest[i] = src[i];
    }

    /* Insert sort */
    for(int i = 1; i < length; ++i){
        temp = dest[i];
        loc = i;
        while(temp < dest[loc - 1] && loc > 0){
            dest[loc] = dest[loc - 1];
            --loc;
        }
        dest[loc] = temp;
    }
}

int main(int argc, char *argv[]){
    int32_t a[] = {3, 2, -5, 7, 13, 4, 1, 7, 8, -8, 6};
    int32_t b[11];
    CopyAndSort(a, b, 11);
    for(int i = 0; i < 11; ++i){
        printf("%d ", b[i]);
    }
}