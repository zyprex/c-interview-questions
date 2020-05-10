/*
 * tcp server : thread concurrent
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <stdlib.h>
#include <pthread.h>
#define PORT 9999

static char buf[80] = {0};

void* run(void* arg);

int main( int argc, char *argv[] )
{
    /*
        sfd: socket 返回的文件描述符，用 sfd 监听并接受客户端连接
        cfd: 客户端链接上来返回的 cfd ，用 cfd 和客户端通信
        client_ip: 客户端IP
        server_addr: 服务器地址
        client_addr: 客户端地址
        client_len: 客户端地址长度
        tid: 线程ID
    */
    int sfd, cfd;
    char client_ip[128];
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;
    pthread_t tid;
    /* */
    sfd = socket(AF_INET, SOCK_STREAM, 0);
    /* */
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    /* */
    bind(sfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    /* */
    listen(sfd, 8);
    printf("server waiting for connection...\n");

    while( 1 ) {
        client_len = sizeof(client_addr);
        cfd = accept(sfd, (struct sockaddr*)&client_addr, &client_len);
        printf( "<client_fd: %d>\n", cfd);
//         printf("client:%s\t%d\n",
//             inet_ntop( AF_INET, &client_addr.sin_addr.s_addr,
//                        client_ip, sizeof(client_ip)) ,
//             ntohs(client_addr.sin_port));
        /* 创建线程，回调 run 方法， cfd 做参数传入 */
        pthread_create(&tid, NULL, run, (void*)cfd);
    }
    return 0;
}

void* run( void* arg )
{
    int cfd = (int)arg;
    pthread_detach(pthread_self());
    int len;
    while( 1 ) {
        len = read( cfd, buf, sizeof(buf) );
        buf[len] = '\0';
        if( len <= 0 ) {
            break;
        }
        printf( "%s\n", buf );
        strcpy(buf, "< server happy! >");
        write( cfd, buf, sizeof(buf));
    }
    close(cfd);
    return NULL;
}

