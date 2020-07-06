#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* get one integer between low and high */
int randomNum(int low, int high)
{
    return ( rand() % high + low );
}

/* get one double number between low and high */
double randomDot(double low,double high)
{
    int integer = rand() % (int)high + (int)low;
    double dot  = rand() / (double)(RAND_MAX);
    while( integer+dot > high || integer+dot < low  ){
        integer = rand() % (int)high + (int)low;
        dot  = rand() / (double)(RAND_MAX);
    }
    return (double)(integer+dot);
}

/* test func */
int main(int argc, const char *argv[])
{
    int i;
    srand((unsigned)time(0));    // seed

    for( i = 0; i < 10; i+=1 ) {
        printf( "%d ", randomNum(-10, -5) );
    }
    putchar(10);
    for( i = 0; i < 10; i+=1){
        printf( "%lf ", randomDot(-100.3,901.6676) );
    }
    return 0;
}

