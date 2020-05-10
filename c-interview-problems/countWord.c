/*
 * count a string's word
 */
#include <stdio.h>

void countWord(char* str)
{
   int i=0;
   while( *str ) {
       if( *str!=' ' && ( *(str+1)==' ' || *(str+1) == '\0' ) )
            i++;
       str++;
   }
   printf( "%d\n", i );
}

int main(int argc, const char *argv[])
{
    char str[128] = " this is an example ";
    countWord(str);
    return 0;
}

