/*
 * simple bubble sort
 */
#include <stdio.h>

void bubblesort(int arr[], int len)
{
    int i, j;
    for( i = 0; i < len - 1; i += 1 ) {
        for( j = 0; j < len - 1 - i; j += 1 ) {
            if( arr[j] > arr[j+1] ) {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

void bubblesort2(int arr[], int len)
{
    int i, j, flag;
    for( i = 0; i < len - 1; i += 1 ) {
        flag = 0;
        for( j = 0; j < len - 1 - i; j += 1 ) {
            if( arr[j] > arr[j+1] ) {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                flag = 1;
            }
        }
        if( !flag )
            break;
    }
}

int main(int argc, const char *argv[])
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int len = sizeof(arr)/sizeof(arr[0]);
    bubblesort2(arr, len);
    int i;
    for( i = 0; i < len; i += 1 ) {
        printf( "%d ", arr[i] );
    }
    return 0;
}

