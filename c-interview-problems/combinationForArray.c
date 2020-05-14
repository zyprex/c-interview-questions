/*
 * print all possible combinations for 1 2 3
 * the 'perm' recursive function reproduced from web
 */
#include <stdio.h>

void combinationFor3(int arr[], int len)
{
    int i, j, k;
    for( i = 0; i < len; i += 1 ) {
        for( j = 0; j < len; j += 1 ) {
            for( k = 0; k < len; k += 1 ) {
                if( i != j && j != k && k != i )
                    printf( "%d\n", arr[i]*100 + arr[j]*10 + arr[k] );
            }
        }
    }
}

void printArr(int arr[], int len)
{
    int i;
    for( i = 0; i < len; i += 1 ) {
        printf( " %d ", arr[i] );
    }
    putchar(10);
}

void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void perm(int arr[], int len, int offset)
{
    int i, temp;
    if( offset == len-1 ) {
        printArr(arr, len);
        return;
    }
    else {
        for( i = offset; i < len; i += 1 ) {
            swap(&arr[i], &arr[offset]);
            perm(arr, len, offset + 1 );
            swap(&arr[i], &arr[offset]);
        }
    }
}

int main(int argc, const char *argv[])
{
    int arr[] = {1, 2, 3, 4};
    int len = sizeof(arr)/sizeof(arr[0]);
//     combinationFor3(arr, len);
    perm(arr, len, 0);
    return 0;
}

