/*
 * convert string to lowercase
 */
#include <stdio.h>

void tolowercase(char str[])
{
    char* s = str;
    while( *s ) {
        if (*s >= 'A' && *s <= 'Z') {
            *s = *s - 'A' + 'a';
        }
        s++;
    }
}

// drive code
int main( int argc, char **argv )
{
    char str1[80];
    printf("input a string:");
    gets(str1);
    tolowercase(str1);
    printf("%s\n",str1);
    return 0;
}
