/*
 * odd position descend order
 * 奇数位降序排列
 */

#include <stdio.h>
#define LEN 10

void oddPosDescend(int arr[])
{
    int i, j, tmp; 
    for( i = 1; i < LEN - 1; i += 2 ) {
        for( j = 1; j < LEN - 1 - i ; j += 2 ) {
            if( arr[j] < arr[j+2] ) {
                tmp = arr[j];
                arr[j] = arr[j+2];
                arr[j+2] = tmp;
            }
        }
    }
}

int main( int argc, char* argv[] )
{
    int data[LEN] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20}, i;
    oddPosDescend(data);
    for( i = 0; i < LEN; i += 1 )
        printf( i < LEN - 1 ? "%d," : "%d", data[i]);
    return 0;
}
