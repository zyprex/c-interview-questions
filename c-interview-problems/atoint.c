/*
 * ascii to integer
 */
#include <stdio.h>

int atoint(char* s)
{
    int i, n;
    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; i++)
        n = 10 * n + (s[i] - '0');
    return n;
}


int main(int argc, const char *argv[])
{
    printf( "%d\n", atoint("1234") );
    return 0;
}

