/*
 * return nth fibonacci sequence number
 */

#include <stdio.h>

long fibonacci(int n)
{
    long prev;
    long temp;
    long result;
    prev = result = 1;
    while( n > 2 ) {
        --n;
        temp = result;
        result += prev;
        prev = temp;
    }
    return result;
}

// driver code
int main( int argc, char *argv[] )
{
    fibonacci(18);
    return 0;
}

