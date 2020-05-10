#include <stdio.h>
#define LEN 10
/*
1
1 1
1 2 1
1 3 3 1
*/

void pascalTriangle()
{
    int i, j;
    int a[LEN][LEN] = {0};
    for( i = 0; i < LEN; i += 1 ) {
        for( j = 0; j <= i; j += 1 ) {
            if( j == 0 || i == j ) {
                a[i][j] = 1;
            }
            else{
                a[i][j] = a[i-1][j-1] + a[i-1][j];
            }
        }
    }
    for( i = 0; i < LEN; i += 1 ) {
        for( j = 0; j < LEN; j += 1 ) {
            if( a[i][j] )
                printf( "%d ", a[i][j] );
        }
        putchar(10);
    }

}

int main(int argc, const char *argv[])
{
    pascalTriangle();
    return 0;
}

