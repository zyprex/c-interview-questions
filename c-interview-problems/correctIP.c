/*
 * test vaild IP string
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void correctIP(char* IPstr)
{
    int i = 0, t = 0;
    char* token;
    token = strtok(IPstr, ".");
    while( token != NULL ) {
//         printf( "%s\n", token );
        t = atoi(token);
        if( t < 0 || t > 255 ) {
            break;
        }
        i++;
        token = strtok(NULL, ".");
    }
    if( i == 4 ) {
        printf("correct IP");
    }
    else {
        printf("incorrect IP");
    }
}

int main(int argc,const char *argv[])
{
    char IPstr[20] = "1.1.1";
    correctIP(IPstr);
    return 0;
}

