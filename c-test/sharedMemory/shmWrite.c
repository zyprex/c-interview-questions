#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_PATH "/tmp/shm"
#define SHM_SIZE 80

int main( int argc, char *argv[] )
{
    char* addr;
    key_t key = ftok(SHM_PATH, 0x6666);

    int shmid = shmget(key, SHM_SIZE, IPC_CREAT|IPC_EXCL|0666);
    if( shmid < 0 ) {
        puts("failed to create shared memory");
        shmid = shmget(key, SHM_SIZE, IPC_CREAT);
        if( shmid < 0 ) {
            return -1;
        }
    }

    addr = shmat(shmid, NULL, 0);
    if( addr <= 0 ) {
        puts("failed to map shared memory");
        return -1;
    }

//     sprintf( addr, "%s", "I am shared memory" );

    printf("shmid:%d\n", shmid);
    while( 1 ) {
        fflush(stdout);
        fscanf(stdin, "%[^\n]", addr);
        puts(addr);
        getchar();
    }

    shmdt(addr);                     // unmap shm
//     shmctl(shmid, IPC_RMID, NULL);   // delete shm

    return 0;
}
