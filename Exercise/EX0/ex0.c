#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

/* *
* <p>This program is to estimate the value of \pi
* <p>The strategy is as below:
*    π = 3 + (4 / (2 x 3 x 4)) - (4 / (4 x 5 x 6)) + (4 / (6 x 7 x 8)) - ...
* <ul>Breaking the series down:
*   <li>the zeroth term in the series is 3
*   <li>the first term in the series is +(4 / (2 x 3 x 4))
*   <li>the second term in the series is -(4 / (4 x 5 x 6))
*   <li>the nth term in the series is (-1)(n+1) x (4 / (2n x (2n+1) x (2n+2)))
*/


int main(int argc, char* argv[]){
    /* Read the integer part of the string */
char intString[strlen(argv[1]) + 1];
if (argc != 2 || sscanf(argv[1], "%[0-9]s", intString) == 0)
{
    printf("Usage: ./ex0 n, where n >= 0. Prints Pi estimated to n terms of the Nilakantha series.\n");
    return 0;
    }
        
    /* N must be positive integer */
    if(strlen(intString) != strlen(argv[1]) || atoi(intString) < 0){
        printf("Usage: ./ex0 n, where n >= 0. Prints Pi estimated to n terms of the Nilakantha series.\n");
        return 0;
    }

    int N = atoi(intString);
    long double estimated_sum = 3;
    for(int i = 1; i <= N; ++i){
        estimated_sum += pow(-1, i + 1) * (4.0 / ((2 * i) * (2 * i + 1) * (2 * i + 2)));
    }
    printf("Our estimate of Pi is %Lf", estimated_sum);
}