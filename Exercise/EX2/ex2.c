#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

/* <p> Prints, in hex, the values of the bytes allocated to some variable */
void DumpHex(void *pData, int byteLen){
    printf("The %d bytes starting at %p are: ", byteLen, pData);
    for(int i = 0; i < byteLen; ++i){
        /* char is signed in system, printf function will sign extend
         all arguments smaller than integer to integer. If the highest bit is 1, it will extend 1.
         That's why we'll get ffff...C0
         https://en.wikipedia.org/wiki/Sign_extension
         */
        printf("%02x ", *((char *)pData + i) & 0xff);
    }
    printf("\n");
}

int main(int argc, char **argv) {
  char     charVal = '0';
  int32_t  intVal = 1;
  float    floatVal = 1.0;
  double   doubleVal  = 1.0;

  typedef struct {
    char     charVal;
    int32_t  intVal;
    float    floatVal;
    double   doubleVal;
  } Ex2Struct;
  Ex2Struct structVal = { '0', 1, 1.0, 1.0 };

  DumpHex(&charVal, sizeof(char));
  DumpHex(&intVal, sizeof(int32_t));
  DumpHex(&floatVal, sizeof(float));
  DumpHex(&doubleVal, sizeof(double));
  DumpHex(&structVal, sizeof(structVal));

  return EXIT_SUCCESS;
}