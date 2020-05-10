/*
 * find the longest substring
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/********************************************************************
 * @fn      maxsubstr
 * @brief   find the longest substring and return it's length
 * @param   str - source string
 * @return  (int) : the length of found substring
 *******************************************************************/
int maxsubstr(char* str)
{
    char* p = str;
    char* a = str;
    char* a_t = str;
    int maxlen = 0;
    int len = 0;

    if( !*str ) return 0;

    while( *p ) {
        if( isdigit(*a) ) {
            if( isdigit(*p) && !isdigit(*(p+1)) ) {
                len = p - a;
                if( len >= maxlen ) {
                    a_t = a;
                    maxlen = len;
                }
                a = p + 1;
            }
        }
        if( isalpha(*a) ) {
            if( isalpha(*p) && !isalpha(*(p+1)) ) {
                len = p - a;
                if( len >= maxlen ) {
                    a_t = a;
                    maxlen = len;
                }
                a = p + 1;
            }
        }
        p++;
    }
    printf( "%.*s\n", maxlen + 1, a_t );
    return maxlen + 1;
}

int main(int argc,const char *argv[])
{
    char str[] = "abcdefg4567123456789asdfgagfafg";
//     char str[] = "";
    printf( "max len:%d\n", maxsubstr(str) );
    return 0;
}

