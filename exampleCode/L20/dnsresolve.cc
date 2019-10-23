#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <iostream>

void Usage(char *progname)
{
    std::cerr << "usage: " << progname << " hostname" << std::endl;
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
    int restval;
    addrinfo hint, *result, *r;
    sockaddr_in6 sa6;

    if (argc != 2) {
        Usage(argv[0]);
    }

    hint.ai_family = AF_UNSPEC;
    hint.ai_socktype = SOCK_STREAM;

    restval = getaddrinfo(argv[1], nullptr, &hint, &result);
     if (restval == 0)
    {
        for (r = result; r != nullptr; r = r->ai_next) {
            if (r->ai_family == AF_INET) {
                char astring4[INET_ADDRSTRLEN];
                sockaddr_in *sa = reinterpret_cast<sockaddr_in *>(r->ai_addr);
                inet_ntop(AF_INET, &(sa -> sin_addr), astring4, INET_ADDRSTRLEN);
                std::cout<<"IPv4: "<<astring4<<std::endl;
            } else if (r -> ai_family == AF_INET6) {
                sockaddr_in6 *sa6 = reinterpret_cast<sockaddr_in6 *>(r->ai_addr);
                char astring6[INET6_ADDRSTRLEN];
                inet_ntop(AF_INET6, &(sa6 -> sin6_addr), astring6, INET6_ADDRSTRLEN);
                std::cout<<"IPv6: "<<astring6<<std::endl;
            } else {
                std::cout<<"Not valid"<<std::endl;
                return EXIT_FAILURE;
            }
        }
    } else {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}