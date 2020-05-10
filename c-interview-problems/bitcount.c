/*
 * Count the number of 1s in a binary number
 */
#include <stdio.h>
/* bitcount: count 1 bits in x */
int bitcount(unsigned x)
{
    int b;
    for (b = 0; x != 0; x >>= 1)
        if (x & 01)
            b++;
    printf( "%d\n", b );
    return b;
}

/* bitcount: count 1 bits in x, more effectve */
int bitcount2(unsigned x)
{
    int b;
    for( b = 0; x; b+=1 ) {
        x &= ( x - 1 );
    }
    printf( "%d\n", b );
    return b;
}


int main(int argc, const char *argv[])
{
    bitcount(101);
    bitcount2(101);
    return 0;
}

