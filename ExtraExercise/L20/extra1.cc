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
    cout<<"Usage: " << name <<endl;
}

bool lookUpByName(char *name);

int main(int argc, char **argv) {
    if(argc != 1) {
        Usage(argv[0]);
    }

    char hostname[100];
    cout << "Input hostname: " << endl;
    while (std::cin.getline(hostname, 100)) {
        if(!lookUpByName(hostname)) {
            Usage(argv[0]);
        }
        cout << "Input hostname: " << endl;
    }
}

bool lookUpByName(char *name){
    int restval;
    addrinfo hints, *results, *r;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((restval = getaddrinfo(name, nullptr, &hints, &results)) == 0)
    {
        for (r = results; r != nullptr; r = r->ai_next)
        {
            if (r->ai_family == AF_INET)
            {
                char astring4[INET_ADDRSTRLEN];
                sockaddr_in *sa = reinterpret_cast<sockaddr_in *>(r->ai_addr);
                inet_ntop(AF_INET, &(sa->sin_addr), astring4, INET_ADDRSTRLEN);
                std::cout << "IPv4: " << astring4 << std::endl;
            }
            else if (r->ai_family == AF_INET6)
            {
                sockaddr_in6 *sa6 = reinterpret_cast<sockaddr_in6 *>(r->ai_addr);
                char astring6[INET6_ADDRSTRLEN];
                inet_ntop(AF_INET6, &(sa6->sin6_addr), astring6, INET6_ADDRSTRLEN);
                std::cout << "IPv6: " << astring6 << std::endl;
            }
            else
            {
                std::cout << "Not valid" << std::endl;
                return false;
            }
        }
    }
    else
    {
        return false;
    }
    return true;
}