#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * <ul>Write a program that:
 *  <li>Uses argc/argv to receive the name of a text file
 *  <li>Reads the contents of the file a line at a time
 *  <li>Parses each line, converting text into a uint32_t
 *  <li>Builds an array of the parsed uint32_t’s
 *  <li>Sorts the array
 *  <li>Prints the sorted array to stdout
 */


int compare(const void *arg1, const void *arg2)
{ 
    return *((u_int32_t *)arg1) > *((u_int32_t *)arg2);
}

int main(int argc, char **argv){
    size_t MAX_FILENAME_SIZE = 50;
    size_t MAX_FILE_LINES = 100;
    size_t MAX_LINE_LENGTH = 100;
    char *filename = argv[1];
    uint32_t numArray[MAX_FILE_LINES];  //Converted Array
    //TODO:free
    char *line = (char *)malloc(sizeof(MAX_LINE_LENGTH));
    FILE* readStream;
    int row = 0;

    if(argc != 2){
        printf("Wrong arguments. Example : ./extra1 in.txt");
        return 0;
    }

    if(access(filename, F_OK) == -1){
        printf("File doesn't exist!");
        return 0;
    }

    readStream = fopen(filename, "r");
    while(getline(&line, &MAX_LINE_LENGTH, readStream) > 0){
        numArray[row] = atoi(line);
        ++row;
    }

    qsort(numArray, row, 4, compare);
    for(int i = 0; i < row; ++i){
        printf("%d\n", numArray[i]);
    }

    free(line);
}