/*
 * basic operation of linked stack
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Lstack {
    int data;
    struct Lstack* next;
}LS_t;

/* create stack */
void lsCreate(LS_t** lstack)
{
    *lstack = (LS_t*)malloc(sizeof(LS_t));
    if( *lstack == NULL ) {
        printf( "%s: malloc failed\n" , __func__);
        exit(1);
    }
    (*lstack)->next = NULL;
}

/* stack push */
void lsPush(LS_t** lstack, int data)
{
    LS_t* node = (LS_t*)malloc(sizeof(LS_t));
    if( node == NULL ) {
        puts("malloc failed");
        return;
    }
    node->data      = data;
    node->next      = (*lstack)->next;
    (*lstack)->next = node;
}

/* stack pop */
LS_t* lsPop(LS_t** lstack)
{
    if( (*lstack)->next == NULL ) {
        printf( "%s: stack empty\n", __func__ );
        return *lstack;
    }
    LS_t* temp      = (*lstack)->next;
    (*lstack)->next = (*lstack)->next->next;
    free(temp);
    temp = NULL;
    return NULL;
}

/* stack destroy */
void lsDestroy(LS_t** lstack)
{
    while( !lsPop(lstack) );
    free(*lstack);
    lstack = NULL;
}

/* stack print */
void lsPrint(LS_t* lstack)
{
    lstack = lstack->next;
    while( lstack != NULL ) {
        printf( "%d ", lstack->data );
        lstack = lstack->next;
    }
    putchar(10);
}

// Drive Code
int main( int argc, char *argv[] )
{
    int i;
    LS_t* lstack = NULL;
    lsCreate(&lstack);
    for( i = 1; i < 10; i+=1 ) {
        lsPush(&lstack, i);
    }
    for( i = 1; i < 10; i+=1 ) {
        lsPrint(lstack);
        lsPop(&lstack);
    }
    lsDestroy(&lstack);
    return 0;
}
