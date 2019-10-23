#include <iostream>
#include <arpa/inet.h>
#include <stdlib.h>

/**
 * const char* inet_ntop(int af, const void* src, char* dst, socklen_t size);
 * 1. Converts network addr in src into buffer dst of size size
 * 2. Returns dst on success; NULL on error
 */

int main(int argc, char ** argv) {
    struct sockaddr_in6 sa6; //IPv6
    char astring[INET6_ADDRSTRLEN]; // IPv6

    inet_pton(AF_INET6, "2001:0db8:63b3:1::3490", &(sa6.sin6_addr));
    inet_ntop(AF_INET6, &(sa6.sin6_addr), astring, INET6_ADDRSTRLEN);
    std::cout<<astring<<std::endl;

    return EXIT_SUCCESS;
}