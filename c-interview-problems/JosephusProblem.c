/*
 * Josephus problem
 */
#include <stdio.h>
#include <stdlib.h>
/********************************************************************
 * @fn      josephus
 * @brief   find last live man
 * @param   n - number of people
 *          k - step length of killing
 * @return  none
 *******************************************************************/
void josephus(int n, int k)
{
    // define linked list structure
    typedef struct man {
        int num;
        struct man* next;
    }MA;

    int i, j;
    MA  *index, *temp = NULL;

    // first man
    MA* head = (MA*)malloc(sizeof(MA));
    if( head == NULL ) {
        puts("malloc failed");
        return;
    }
    head->num = 1;     // head number 1
    head->next = head; // loop linked list
    // other man
    for(  i = n; i > 1; i-- ) {
        index = (MA*)malloc(sizeof(MA));
        index->num = i;  // insert man 2~n
        index->next = head->next;
        head->next = index;
    }
    // start kill before head
    for(  i = 0; i < n - 2; i+=1 ) {
        index = index->next;
    }
    // kill procedure
    for(  i = 0; i < n - 1 ; i+=1 ) {
        for( j = 0; j < k - 1; j+=1 ) {
            index = index->next;
            printf( "%d > ", index->num );
        }
        // unlucky man! x_x
        printf( "NO.%d is dead\n", index->next->num );
        temp = index->next;
        index->next = index->next->next;
        free(temp);
        temp = NULL;

    }
    printf( "NO.%d is live!\n", index->num ); // result
    free(index);
    index = NULL;
    return;
}


// Drive Code
int main(int argc,const char *argv[])
{
//     josephus(3, 1);// 3 1 = 3
//     josephus(5, 2);// 5 2 = 3
//     josephus(7, 3);// 7 3 = 4
    return 0;
}

