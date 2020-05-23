#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <string.h>

#define SHM_PATH "/tmp/shm"
#define SHM_SIZE 64

#define R 0
#define W 1

// see man semctl
union semun {
    int              val;    /* Value for SETVAL */
    struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  *array;  /* Array for GETALL, SETALL */
    struct seminfo  *__buf;  /* Buffer for IPC_INFO
                                           (Linux-specific) */
}un;

void semP(int semid, int num); // 对semid 的 num 号进行 P 操作
void semV(int semid, int num); // 对semid 的 num 号进行 V 操作

int main(int argc,const char *argv[])
{
    key_t key;
    int shmid, semid;
    char* shmaddr = NULL;

    struct shmid_ds buf;

    key = ftok(SHM_PATH, 0x6666);

    semid = semget(key, 2, IPC_CREAT|IPC_EXCL|0666);
    if( semid == -1 ) {
        if( errno ==EEXIST ) {
            semid = semget(key, 2, 0666);
        }
        else {
            perror("semget");
            exit(-1);
        }
    }
    else { // first run initial
        un.val = 0;
        semctl(semid, R, SETVAL, un); // R(0)->0
        un.val = 1;
        semctl(semid, W, SETVAL, un); // W(1)->1
    }

    shmid = shmget(key, SHM_SIZE, IPC_CREAT|0666);

    shmaddr = shmat(shmid, NULL, 0);

    while( 1 ) {
        semP(semid, R); // 申请资源
        printf( "%s", shmaddr );
        semV(semid, W); // 资源可写
        if( !strncmp(shmaddr, "quit", 4 ) ){
            break;
        }
    }

    shmdt(shmaddr);

//     shmctl(shmid, IPC_STAT, &buf);
//     if( !buf.shm_nattch ) {
//         shmctl(shmid, IPC_RMID, NULL);
//         semctl(semid, 0, IPC_RMID, NULL);
//     }

    return 0;
}



void semP(int semid, int num)
{
    int ret;
    struct sembuf buf = {num, -1, 0};
    ret = semop(semid, &buf, 1); // operate one sem
    if( ret == -1 ) {
        perror("semop");
        exit(-1);
    }
}

void semV(int semid, int num)
{
    int ret;
    struct sembuf buf = {num, 1, 0};
    ret = semop(semid, &buf, 1); // operate one sem
    if( ret == -1 ) {
        perror("semop");
        exit(-1);
    }
}
