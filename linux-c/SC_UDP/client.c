/*
 * udp client
 */
#include <stdio.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define PORT 9909
#define IP "192.168.40.129"

static char buf[80] = {0};

int main(int argc, const char *argv[])
{
    int cfd;
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    /**/
    cfd = socket(AF_INET, SOCK_DGRAM, 0);
    /**/
    bzero(&client_addr, sizeof(client_addr));
    client_addr.sin_family      = AF_INET;
    client_addr.sin_port        = htons(PORT);
    client_addr.sin_addr.s_addr = inet_addr(IP);
    /**/
    while( 1 ) {
        bzero(buf, sizeof(buf));
        fgets(buf, sizeof(buf), stdin);
        sendto(cfd, buf, strlen(buf),0,
               (struct sockaddr*)&client_addr, client_len );
    }
    close(cfd);
    return 0;
}
