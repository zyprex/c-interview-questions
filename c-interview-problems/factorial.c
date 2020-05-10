/*
 * calculate n!
 */
#include <stdio.h>
int factorial(int n)
{
    if(n == 1)
        return 1;
    else
        return (factorial(n-1) * n);
}

int factorial2(int n)
{
    int result = 1, i;
    for( i = 1; i <= n; i+=1 )
        result *= i;
    return result;
}

int main(int argc, const char *argv[])
{
    printf( "%d\n", factorial2(3) );
    return 0;
}

