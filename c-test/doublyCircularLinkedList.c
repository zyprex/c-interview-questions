/*
 *  Doubly(Bi-Directional) Circular Linked List operations
 */
#include <stdio.h>
#include <stdlib.h>

/* define the node structure */
typedef struct DCLinkedList {
    int data;
    struct DCLinkedList* next;
    struct DCLinkedList* prev;
}DCLL_t;

/* create head node with new data */
DCLL_t* dcllCreate(int data)
{
    DCLL_t* head = (DCLL_t*)malloc(sizeof(DCLL_t));
    if( head == NULL ) {
        printf("%s: malloc failed", __func__);
        return NULL;
    }
    head->data = data;
    head->next = head;
    head->prev = head;
    return head;
}

/* insert after  head */
void dcllInsAfter(DCLL_t* head, int data)
{
    DCLL_t* node = (DCLL_t*)malloc(sizeof(DCLL_t));
    if( node == NULL ) {
        printf("%s: malloc failed", __func__);
        return;
    }
    node->data = data;     //fill data
    node->prev = head;       // node link to head
    node->next = head->next; // node link to head-next
    head->next->prev = node; // head-next link to node
    head->next       = node; // head link to node
}

/* insert before head */
void dcllInsBefore(DCLL_t* head, int data)
{
    DCLL_t* node = (DCLL_t*)malloc(sizeof(DCLL_t));
    if( node == NULL ) {
        printf("%s: malloc failed", __func__);
        return;
    }
    node->data = data;     // fill data
    node->prev = head->prev; // node link to head-prev
    node->next = head;       // node link to head
    head->prev->next = node; // head-prev link to node
    head->prev       = node; // head link to node
}

/* delete after  head */
void dcllDelAfter(DCLL_t* head)
{
    if( head->next == head ) {
        printf("%s: bare head", __func__);
        return;
    }
    DCLL_t* temp = head->next;   // save head-next
    head->next->next->prev = head;             // link backward trace
    head->next             = head->next->next; // link forward  trace
    free(temp);
    temp = NULL;
}

/* delete before head */
void dcllDelBefore(DCLL_t* head)
{
    if( head->next == head ) {
        printf("%s: bare head", __func__);
        return;
    }
    DCLL_t* temp = head->prev;   // save head-prev
    head->prev->prev->next = head;             // link forward  trace
    head->prev             = head->prev->prev; // link backward trace
    free(temp);
    temp = NULL;
}

/* print list */
void dcllPrint(DCLL_t* head)
{
    DCLL_t* index = head->next;
    printf( "(%d) ", head->data );
    while( index->next != head->next) {
        printf( "%d ", index->data );
        index = index->next;
    }
    /* int i; */
    /* for( i = 0; i < 4; i+=1 ) { */
    /*     printf( "%d ", index->data ); */
    /*     index = index->next; */
    /* } */
    putchar(10);
}

/* destroy list */
void dcllDestroy(DCLL_t* head)
{
    while( head->next != head )
        dcllDelAfter(head);
    free(head);
    head = NULL;
}

/* find data */
int dcllFind(DCLL_t* head, int n)
{
    if ( n == 0 )
        return head->data;
    DCLL_t* index = head;
    while( n )
        index = ( n > 0 ) ? (--n, index->next) : (++n, index->prev);
    return index->data;
}


// Drive Code
int main(int argc, const char *argv[])
{
    DCLL_t* head = dcllCreate(0);
    int i;
    for(  i = 0; i < 4; i+=1 ) {
        dcllInsAfter(head,  2 * i + 3 ); // 3 5 7 9
        dcllInsBefore(head, 2 * i + 2 ); // 2 4 6 8
    }
    dcllDelBefore(head);
    dcllDelAfter(head);
    dcllPrint(head);
    printf("{%d}\n", dcllFind(head, -5));

    dcllDestroy(head);
    return 0;
}

