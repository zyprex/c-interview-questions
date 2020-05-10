#include <stdio.h>
/* use define macro to debug */
#define DEBUG_VALUE_INT(v) printf(#v" is equal to %d.\n",v )
#define DEBUG_VALUE_LONG(v) printf(#v" is equal to %ld.\n",v )

int main( int argc, char *argv[] )
{
    int a = 1;
    DEBUG_VALUE_INT(a);
    DEBUG_VALUE_INT(12);
    return 0;
}
