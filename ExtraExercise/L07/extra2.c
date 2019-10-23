#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50

/** <ul>Write a program that:
  *   <li>Loops forever; in each loop:
  *      <li>Prompt the user to input a filename
  *      <li>Reads a filename from stdin 
  *      <li>Opens and reads the file
  *      <li>Prints its contents to stdout
  */

int main(int argc, char **argv){
    size_t MAX_LINE_LENGTH = 100;
    char filename[MAX_FILENAME_LENGTH];
    char *line;
    FILE *readStream;

    while(1){
        printf("Input filename of the file u want to print:\n");
        scanf("%s", filename);

        if(!strcmp(filename, "QUIT")){
            return 0;
        }

        if (access(filename, F_OK) == -1)
        {
            printf("Invalid filename!\n");
        }

        readStream = fopen(filename, "r");

        while (getline(&line, &MAX_LINE_LENGTH, readStream) > 0)
        {
            printf("%s", line);
        }
        printf("\n");
    }  
}