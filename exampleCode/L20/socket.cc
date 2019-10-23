#include <iostream>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char ** argv) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        std::cerr<<strerror(errno)<<std::endl;
        return EXIT_FAILURE;
    }
    std::cout<<"Successfully created a socket!"<<std::endl;
    close(sockfd);
    return EXIT_SUCCESS;
}