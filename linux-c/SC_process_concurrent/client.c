/*
 * tcp client : thread concurrent
 */
#include <stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/wait.h>

#define PORT 9999
// #define IP "192.168.1.115" //  "127.0.0.1"
#define IP "192.168.40.129" //  "127.0.0.1"
static char buf[80] = {0};

int main( int argc, char *argv[] )
{
    /*
        cfd: 客户端的 socket 文件描述符
        serv_addr: 服务器地址
    */
    int cfd;
    struct sockaddr_in serv_addr;

    cfd = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family      = AF_INET;
    serv_addr.sin_port        = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr(IP);
    bzero(&(serv_addr.sin_zero), 8);

    connect(cfd, (struct sockaddr*)&serv_addr, sizeof(struct sockaddr));
    printf("<connect success>\n");

    int len;
    while( 1 ) {
        scanf("%s", buf);
        write(cfd, buf, sizeof(buf));
        len = read(cfd, buf, sizeof(buf));
        buf[len] = '\0';
        printf( "--> %s\n", buf );
    }
    close(cfd);
    return 0;
}
