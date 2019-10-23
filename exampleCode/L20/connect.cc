#include <arpa/inet.h>
#include <assert.h>
#include <errno.h>
#include <netdb.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <iostream>
using namespace std;

void Usage(char *progname)
{
    std::cerr << "usage: " << progname << " hostname port" << std::endl;
    exit(EXIT_FAILURE);
}

bool LookupName(char *name,
                unsigned short port,
                struct sockaddr_storage *ret_addr,
                size_t *ret_addrlen);

int main(int argc, char ** argv) {
    if(argc != 3) {
        Usage(argv[0]);
        return EXIT_FAILURE;
    }

    unsigned short port;
    if(sscanf(argv[1], "%hu", &port) != 1) {
        Usage(argv[0]);
        return EXIT_FAILURE;
    }

    sockaddr_storage *ret_addr;
    size_t ret_addrlen;
    if(!LookupName(argv[1], port, ret_addr, &ret_addrlen)) {
        Usage(argv[0]);
    }

    int sock_fd = socket(ret_addr ->ss_family, SOCK_STREAM, 0);
    if(sock_fd == -1) {
        std::cerr << "socket() failed: " << strerror(errno) << std::endl;
        return EXIT_FAILURE;
    }

    int ret = connect(sock_fd, reinterpret_cast<sockaddr *>(&ret_addr), ret_addrlen);
    if(ret == -1) {
        std::cerr << "connect() failed: " << strerror(errno) << std::endl;
    }

    close(sock_fd);
    return EXIT_SUCCESS;
}

bool LookupName(char *name,
                unsigned short port,
                struct sockaddr_storage *ret_addr,
                size_t *ret_addrlen)
{
    struct addrinfo hints, *results;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if(int retval = getaddrinfo(name, nullptr, &hints, &results) != 0) {
        cout << "GetAddrInfo failed"<<endl;
        std::cerr << gai_strerror(retval) << std::endl;
    }

    if(results->ai_family == AF_INET) {
        sockaddr_in * sa = reinterpret_cast<sockaddr_in *>(results->ai_addr);
        sa->sin_port = htons(port);
    }
    else if(results->ai_family == AF_INET6) {
        sockaddr_in6 *sa6 = reinterpret_cast<sockaddr_in6 *>(results->ai_addr);
        sa6->sin6_port = htons(port);
    }
    else {
        std::cerr << "getaddrinfo failed to provide an IPv4 or IPv6 address";
        std::cerr << std::endl;
        freeaddrinfo(results);
        return false;
    }

    assert(results != nullptr);
    memcpy(ret_addr, results->ai_addr, results->ai_addrlen);
    *ret_addrlen = results->ai_addrlen;

    freeaddrinfo(results);
    return true;
}