#include <stdio.h>
#include <sys/dir.h>
#include <stdlib.h>
#include <sys/errno.h>
#include <regex.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/** <ul>Write a C program that:
  *     <li>Accepts a directory name as a command-line argument 
  * (the directory name can be a simple name or a longer file path 
  * and might, or might not, have a trailing '/' at the end)
  *     <li>Scans through the directory looking for filenames that end 
  * in the four characters ".txt" (you do not need to scan subdirectories recursively)
  *     <li>Reads the contents of those files using open / read / close,
  * copying the contents to stdout (you may use C standard library functions to write to stdout, 
  * but you must use open / read / close to read the files)
*/

int main(int argc, char **argv){
    struct dirent *entry;
    int filename_length, status, fd;
    regmatch_t pmatch[1];
    regex_t reg;
    const char *pattern = ".*\.txt";
    char line[100];


    if(argc != 2){
        fprintf(stderr, "Usage: ./dirdump <path>\n");
        return EXIT_FAILURE;
    }

    DIR* dirp = opendir(argv[1]);
    entry = readdir(dirp);
    if(dirp == NULL){
        fprintf(stderr, "Could not open directory\n");
        return EXIT_FAILURE;
    }

        while (entry)
    {
        regcomp(&reg, pattern, REG_EXTENDED);
        status = regexec(&reg, entry->d_name, 1, pmatch, 0); 
        if(status == 0) {
            fd = open(entry->d_name, O_RDONLY);
            while(read(fd, line, 100) > 0){
                fprintf(stdout, "%s\n", line);
            }
        }
        errno = 0;
        entry = readdir(dirp);
    }

    if(errno){
        perror("Error reading directory");
        return EXIT_FAILURE;
    }

    regfree(&reg);
    closedir(dirp);
    return EXIT_SUCCESS;
}