/*
 * signed convert to unsigned
 */
#include <stdio.h>
int main(int argc,const char *argv[])
{
    unsigned int a = 6;
    int b = -20;
    printf( "%u\n", a + b );
    ( a + b > 6 ) ? puts( "true" ) : puts( "false" ); // true
    printf( "%u\n", a - b );
    ( a - b > 6 ) ? puts( "true" ) : puts( "false" ); // true

    return 0;
}

