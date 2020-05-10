#include <stdio.h>
#define ARRL(X) sizeof(X)/sizeof(*X)
/*
   [0...len-2]
        [1...len-1]
        [2...len-1]
        [3...len-1]
        [len-2...len-1]
*/
void selectsort(int s[], int len)
{
    int i, j, k;
    for( i = 0; i < len-1; i += 1 ) {
        k = i;
        for( j = i+1; j < len; j += 1 ) {
            if( s[k] > s[j] ) {
                k = j;
            }
        }
        if( k != i ) {
            int tmp = s[k];
            s[k] = s[i];
            s[i] = tmp;
        }
    }
    for( i = 0; i < len; i += 1 ) {
        printf( "%d ", s[i] );
    }
}

int main(int argc,const char *argv[])
{
    int chaos[]={26,48,17,55,36,31,35,54,27,14,13,12,17,19,33};
    int len = ARRL(chaos);
    selectsort(chaos, len);
    return 0;
}

