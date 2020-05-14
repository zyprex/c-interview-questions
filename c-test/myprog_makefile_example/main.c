#include "foo.h"
#include "bar.h"
#include <stdio.h>
int main( int argc, char *argv[] )
{
    printf( "%s & %s\n", foofname(), barfname() );
    getchar();
    return 0;
}
