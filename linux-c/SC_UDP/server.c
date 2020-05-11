/*
 * udp server
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

int main(int argc,const char *argv[])
{
    int sfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char client_ip[20];

    sfd = socket(AF_INET, SOCK_DGRAM, 0);

    /* 端口复用*/
    int opt = 1;
    setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    /* setsockopt(sfd,SOL_SOCKET,SO_BROADCAST,&opt,sizeof(opt)); */
    /**/
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family      = AF_INET;
    server_addr.sin_port        = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    /**/
    bind(sfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    puts( "<UDP start>" );
    /**/
    while( 1 ) {
        bzero(buf,sizeof(buf));

        recvfrom(sfd, buf, sizeof(buf), 0,
                (struct sockaddr*)&client_addr, &client_len);

        inet_ntop( AF_INET,
                   (void*)&client_addr.sin_addr,
                   client_ip,
                   sizeof(client_addr) );

        printf( "<ipv4 addr:%s port:%d>\n"
                "%s",
                client_ip,
                ntohs(client_addr.sin_port),
                buf );

    }
    close(sfd);
    return 0;
}

