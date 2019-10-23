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

void Usage(char *name) {
    cout<<"Usage: "<<name<<endl;
}

bool lookUpByName(char *name, unsigned short port, sockaddr_storage *ret_addr, size_t *addrlen);


//  ./writeToServer localhost 5555 output.txt
int main(int argc, char **argv)
    {
        unsigned short port;
        sockaddr_storage *ret_addr = 
            (sockaddr_storage *)malloc(sizeof(sockaddr_storage));
        size_t addrlen;

        if (argc != 4)
        {
            Usage(argv[0]);
        }
        if (sscanf(argv[2], "%hu", &port) != 1)
        {
            Usage(argv[0]);
        }

        // if (!lookUpByName(argv[1], port, ret_addr, &addrlen))
        // {
        //     Usage(argv[0]);
        // }

        int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (sock_fd == -1)
        {
            std::cerr << "socket() failed: " << strerror(errno) << std::endl;
            return EXIT_FAILURE;
        }

        struct sockaddr_in6 *sa6; //IPv6
        inet_pton(AF_INET6, "127.0.0.1", &(sa6->sin6_addr));

        int connect_result = connect(sock_fd, reinterpret_cast<sockaddr *>(sa6), addrlen);
        if (connect_result == -1)
        {
            std::cerr << "connect() failed: " << strerror(errno) << std::endl;
        }

        FILE *file_fd = fopen(argv[3], "r");
        char *line[200];
        while (1)
        {
            int result = fread(line, 1, 200, file_fd);
            if(result == -1 || result == 0) {
                int wres = write(sock_fd, line, 200);
                if (wres == 0)
                {
                    std::cerr << "socket closed prematurely" << std::endl;
                    close(sock_fd);
                    return EXIT_FAILURE;
                }
                if (wres == -1)
                {
                    if (errno == EINTR)
                        continue;
                    std::cerr << "socket write failure: " << strerror(errno) << std::endl;
                    close(sock_fd);
                    return EXIT_FAILURE;
                }
            }
        }
 }

bool lookUpByName(char *name, unsigned short port, sockaddr_storage *ret_addr, size_t *addrlen) 
{
    addrinfo hints, *results;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    int retval = getaddrinfo(name, nullptr, &hints, &results);
    if (retval == 0)
    {
        if(results->ai_family == AF_INET) {
            sockaddr_in *sa = reinterpret_cast<sockaddr_in *>(results->ai_addr);
            sa->sin_port = htons(port);
            char astring4[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, &(sa->sin_addr), astring4, INET_ADDRSTRLEN);
            std::cout << "IPv4: " << astring4 << std::endl;
        }
        else if(results->ai_family == AF_INET6) {
            sockaddr_in6 *sa6 = reinterpret_cast<sockaddr_in6 *>(results->ai_addr);
            sa6->sin6_port = htons(port);
            char astring6[INET6_ADDRSTRLEN];
            inet_ntop(AF_INET6, &(sa6->sin6_addr), astring6, INET6_ADDRSTRLEN);
            std::cout << "IPv6: " << astring6 << std::endl;
        }
        else{
            std::cerr << "getaddrinfo failed to provide an IPv4 or IPv6 address";
            freeaddrinfo(results);
            return false;
        }

        assert(results != nullptr);
        memcpy(ret_addr, results->ai_addr, results->ai_addrlen);
        *addrlen = results->ai_addrlen;
        freeaddrinfo(results);
        return true;
    }else {
        cout << "GetAddrInfo failed" << endl;
        std::cerr << gai_strerror(retval) << std::endl;
        return false;
    }
}