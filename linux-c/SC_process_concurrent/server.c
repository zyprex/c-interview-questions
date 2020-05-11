/*
 * tcp server : process concurrent
 */
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <sys/wait.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define PORT 9999

static char buf[80] = {0};

void recycle_sigchlid(int num)
{
    pid_t pid;
    // 回收任意子进程，若无退出的子进程立即返回
    while( (pid = waitpid(-1, NULL, WNOHANG)) > 0) {
        printf( "child died, pid = %d\n", pid );
    }
}


int main( int argc, char *argv[] )
{
    /*
        sfd: socket 返回的文件描述符，用 sfd 监听并接受客户端连接
        cfd: 客户端链接上来返回的 cfd ，用 cfd 和客户端通信
        server_addr: 服务器地址
        client_addr: 客户端地址
        client_ip: 客户端IP
        client_len: 客户端地址长度
        pid: 进程ID
        len: 从客户端读取的长度
    */
    int sfd, cfd;
    struct sockaddr_in server_addr, client_addr;
    char client_ip[128];
    socklen_t client_len = sizeof(client_addr);
    pid_t pid;
    int len;

    /**/
    sfd = socket(AF_INET, SOCK_STREAM, 0);
    /* 端口复用*/
    int opt = 1;
    setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    /**/
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family      = AF_INET;
    server_addr.sin_port        = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    /**/
    bind(sfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    /**/
    listen(sfd, 20);
    puts( "<accept connections...>" );

    while( 1 ) {
        cfd = accept(sfd, (struct sockaddr*)&client_addr, &client_len);

        printf( "<client ip:%s, port: %d>\n",
                inet_ntop( AF_INET, &client_addr.sin_addr,
                    client_ip, sizeof(client_ip)),
                ntohs(client_addr.sin_port) );

        pid = fork();
        if( pid == 0 ) {
            close(sfd);
            while( 1 ) {
                len = read(cfd, buf, sizeof(buf));
                if( len == 0 ) {
                    puts( "<client quit!>" );
                    break;
                }
                buf[len] = '\n';
                write(STDOUT_FILENO, buf, len+1);
                write(cfd, buf, len);
            }
            close(cfd);
            return 0;
        }
        else if( pid > 0 ) {
            /*
              父进程，负责对子进程pcb资源的回收
              使用信号来回收，子进程结束会给父进程发送SIGCHLD信号
              默认父进程会屏蔽此信号，若父进程想回收子进程资源，
              可以捕捉此信号
            */

            // 信号捕捉: 注册捕捉函数
            struct sigaction act;
            act.sa_flags = 0;
            act.sa_handler = recycle_sigchlid;// 回调函数，通过sa_handler指针调用
            sigemptyset(&act.sa_mask);        // 将信号集初始化为空
            sigaction(SIGCHLD, &act, NULL);
        }
    }
    return 0;
}
