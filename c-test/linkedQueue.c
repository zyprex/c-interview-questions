/*
 * basic operation of linked queue
 */
/****************************************
  [head]--->[first]--->[ ... ]--->[last]
    ↑                               ↑
  lq_ref[0]                    lq_ref[1]
****************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct Lqueue {
    int data;
    struct Lqueue* next;
}LQ_t;

/* create queue with new data */
void lqCreate(LQ_t* lq_ref[], int data)
{
    LQ_t* lq_node = NULL;
    lq_node = (LQ_t*)malloc(sizeof(LQ_t));
    if( !lq_node ) {
        printf( "%s: malloc failed\n" , __func__);
        exit(1);
    }
    lq_node->data = data; // head node data
    lq_node->next = NULL;
    lq_ref[0]     = lq_node;
    lq_ref[1]     = lq_node;
}

/* last enter the queue  */
void lqEnter(LQ_t* lq_ref[], int data)
{
    LQ_t* lq_node = NULL;
    lq_node = (LQ_t*)malloc(sizeof(LQ_t));
    if( !lq_node ) {
        printf( "%s: malloc failed\n" , __func__);
        exit(1);
    }
    lq_node->data = data;
    lq_node->next = NULL;      // new node created
    lq_ref[1]->next = lq_node; // link to new node
    lq_ref[1]       = lq_node; // move ptr to new node
}

/* first leave the queue  */
LQ_t* lqLeave(LQ_t* lq_ref[])
{
    if( lq_ref[0] == lq_ref[1] ) {
        printf( "%s: queue empty\n", __func__ );
        return lq_ref[0];
    }
    LQ_t* temp      = lq_ref[0]->next;
    lq_ref[0]->next = lq_ref[0]->next->next;
    if( lq_ref[0]->next == NULL ) { // we release the last element
        lq_ref[1] = lq_ref[0];      // set queue last ptr back to head!
    }
    free(temp);
    temp = NULL;
    return NULL;
}

/* destroy entire queue */
void lqDestroy(LQ_t* lq_ref[])
{
    while( !lqLeave(lq_ref) );
    free(lq_ref[0]);
    lq_ref[0] = NULL;
}

/* print queue */
void lqPrint(LQ_t* lq_ref[])
{
    LQ_t* n = lq_ref[0]->next; // skip head node
    while( n ) {
        printf( "%d ", n->data );
        n = n->next;
    }
    putchar(10);
}

// Drive Code
int main( int argc, char *argv[] )
{
    int i;
    LQ_t* lq_ref[2]; // [0] head node, [1] last
    lqCreate(lq_ref, 0);
    for( i = 1; i < 10; i+=1 ) {
        lqEnter(lq_ref, i);
    }
    for( i = 1; i < 10; i+=1 ) {
        lqPrint(lq_ref);
        lqLeave(lq_ref);
    }
    lqDestroy(lq_ref);
    return 0;
}
