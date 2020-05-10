/*
 * reverse string
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* reverseStr(char* src)
{
    int len = strlen(src);
    char* dest = (char*)malloc(len);
    char* d = dest;
    char* s = &src[len-1];
    while( (len--) != 0 ) {
        *(d++) = *(s--);
    }
    return dest;
}


void reverseStr2(char* s)
{
    int len = 0;
    char *a = s;
    while(*(s++)) len++;
    char *b = s - 2;
    char t;
    while( a < b ) {
        t = *a;
        *a = *b;
        *b = t;
        a++;
        b--;
    }
    printf( "%s\n", s - len - 1 );
}


int main(int argc, const char *argv[])
{
    char src[]="hello, world";
    printf( "%s\n", reverseStr(src) );
    reverseStr2(src);
    return 0;
}

