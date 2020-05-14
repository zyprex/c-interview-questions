#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MQ_PATH "/tmp/mq"
#define MSG_SIZE 64

struct msgbuf {
    long mtype;
    char mtext[MSG_SIZE];
};

int main( int argc, char *argv[] )
{
    key_t key;
    struct msgbuf buf;
    key = ftok(MQ_PATH, 0x6666);
    int msg_id = msgget(key, IPC_CREAT|IPC_EXCL|0666);
    if( msg_id < 0 ) {
        if( errno == EEXIST ) {
            msg_id = msgget(key, 0666);
            puts("msgqueue exist");
        }
        else {
            perror("msgget");
            exit(1);
        }
    }

    msgrcv(msg_id, &buf, MSG_SIZE, 1, 0);
    printf( "msg_id:%d\ncontent:%s\n", msg_id, buf.mtext);

    return 0;
}
