#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**     Write a C program that accepts a filename as a single command-line argument. 
 *  The program should read the file, copying the contents of the file to stdout 
 *  in reverse order, character by character. */

int main(int argc, char **argv){
    size_t file_size = 0;
    char *filename = argv[1];
    FILE *readStream;
    char symbol;

    if(argc != 2){
        printf("Invalid command. Example: ./ex5 foo.txt\n");
        return 0;
    }

    if(access(filename, F_OK) == -1){
        printf("File doesn't exist!\n");
    }

    readStream = fopen(filename, "rb");
    //Get file size
    fseek(readStream, 1, SEEK_END);
    file_size = ftell(readStream);

    for(int i = 1; i < file_size; ++i){
        fseek(readStream, -i, SEEK_END);
        printf("%c", fgetc(readStream));
    }
}