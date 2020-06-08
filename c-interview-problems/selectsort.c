/*
 * select sort
 */
#include <stdio.h>
#define ARRL(X) sizeof(X)/sizeof(*X)

void selectsort(int arr[], int len)
{
    int i, j, k;
    for( i = 0; i < len-1; i += 1 ) {
        k = i;
        for( j = i+1; j < len; j += 1 ) {
            if( arr[k] > arr[j] ) {
                k = j;
            }
        }
        if( k != i ) {
            int tmp = arr[i];
            arr[i] = arr[k];
            arr[k] = tmp;
        }
    }
    for( i = 0; i < len; i += 1 ) {
        printf( i == len-1 ? "%d" : "%d ", arr[i] );
    }
}

int main(int argc,const char *argv[])
{
    int chaos[]={26,48,17,55,36,31,35,54,27,14,13,12,17,19,33};
    int len = ARRL(chaos);
    selectsort(chaos, len);
    return 0;
}

