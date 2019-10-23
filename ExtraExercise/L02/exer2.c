#include <stdint.h>
#include <string.h>
#include <stdio.h>

/** <p>Accepts a string as a parameter
 *  <ul>Returns:
        <li>The first white-space separated word in the string as a newly-allocated string
        <li>the size of that word
 */
int WordAndnSize(char src[], char dst[])
{
    int length = strlen(src);
    int lengthOfWord = 0;
    char *word;
    for(int i = 0; i < length; ++i){
        if(src[i] == ' '){
            lengthOfWord = i;
            break;
        }
        else{
            dst[i] = src[i];
            ++lengthOfWord;
        }   
    }
    return lengthOfWord;
}

int main(int argc, char *argv[]){
    char *myString = "Hello My name is Isabella!";
    char dst[strlen(myString) + 1];
    int firstWordSize = WordAndnSize(myString, dst);
    printf("First Word is %s\nLength of the first word is %d", dst, firstWordSize);
}