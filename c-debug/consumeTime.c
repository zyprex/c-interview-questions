#include <time.h>
#include <stdio.h>
#define MSEC 1000
int main()
{
    clock_t start_t, end_t;
    double total_t;

    start_t = clock();
    printf("start_t= %ld\n", start_t);

    do {
        end_t = clock();
    }while( (end_t - start_t) <= MSEC );
    printf("end_t = %ld\n", end_t);

    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;

    printf("Consumed Time: %f seconds \n", total_t  );
    printf("exited normally\n");
    return 0;
}

