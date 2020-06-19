#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomNum(int low, int high)
{
    return ( rand() % high + low );
}

int main(int argc, const char *argv[])
{
    int i;
    srand((unsigned)time(0));    // seed
    for( i = 0; i < 10; i+=1 ) {
        printf( "%d ", randomNum(10, 50) );
    }
    return 0;
}

