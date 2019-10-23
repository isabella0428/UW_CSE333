 #include <iostream>
 #include <arpa/inet.h>

/*
 * int inet_pton(int af, const char* src, void* dst);
 * 1. Converts human-readable string representation (“presentation”) to network byte ordered address
 * 2. Returns 1 (success), 0 (bad src), or -1 (error)
 */

int main(int argc, char **argv) {
    struct sockaddr_in sa4;     //IPv4
    struct sockaddr_in6 sa6;    //IPv6

    inet_pton(AF_INET, "192.0.2.1", &(sa4.sin_addr));
    std::cout<<sa4.sin_addr.s_addr<<std::endl;
    inet_pton(AF_INET6, "2001:db8:63b3:1::3490", &(sa6.sin6_addr));
    std::cout<<sa6.sin6_addr.s6_addr<<std::endl;

    return EXIT_SUCCESS;
}
