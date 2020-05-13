/*
 * basic operation of singly linked list
 */
#include <stdio.h>
#include <stdlib.h>

/* define the linked list node structure */
typedef struct LinkedList {
    int data;
    struct LinkedList* next;
}LL_t;

/* create linked list head node */
LL_t* llCreate(void)
{
    LL_t* head = (LL_t*)malloc(sizeof(LL_t));
    if( head == NULL ) {
        puts("malloc failed");
        return;
    }
    head->next = NULL;
    return head;
}

/* push a data into linked list */
void llPush(LL_t* head, int data)
{
    if( head == NULL ) {
        puts("linked list not exist!");
        return;
    }
    // filled node data
    LL_t* new_node = (LL_t*)malloc(sizeof(LL_t));
    new_node->data = data;
    // link node
    new_node->next = head->next;
    head->next = new_node;
}

/* append at end */
void llAppend(LL_t* head, int data)
{
    if( head == NULL ) {
        puts("linked list not exist!");
        return;
    }
    // filled node
    LL_t* new_node = (LL_t*)malloc(sizeof(LL_t));
    new_node->data = data;
    new_node->next = NULL;
    // link node
    LL_t* p = head;
    while(p->next) p = p->next;
    p->next = new_node;
}

/* insert data at n'th position */
void llInsert(LL_t* head, int data, int pos)
{
    if( head == NULL ) {
        puts("linked list not exist!");
        return;
    }
    // find node
    LL_t* p = head;
    while( --pos && p->next ) p = p->next;
    // insert
    LL_t* new_node = (LL_t*)malloc(sizeof(LL_t));
    new_node->data = data;
    new_node->next = p->next;
    p->next = new_node;
}

/* delete data at n'th position */
void llDelete(LL_t* head, int pos)
{
    if( head == NULL ) {
        puts("linked list not exist!");
        return;
    }
    // find node
    LL_t* p = head;
    while( --pos && p ) p = p->next;
    // remove node
    LL_t* tmp = p->next;
    p->next = p->next->next;
    free(tmp);
    tmp = NULL;
}

/* destroy entire linked list */
void llDestroy(LL_t** head_ref)
{
    LL_t* p = *head_ref;
    LL_t* temp;
    while( p ) {
        temp = p->next; // save next pointer
        free(p);        // p is free
        p = temp;       // p to next position
    }
    *head_ref = NULL;  //unref head
}

/* replace n'th data by new data*/
void llChange(LL_t* head, int data, int pos)
{
    LL_t* p = head;
    while( --pos && p ) p = p->next;
    p->next->data = data;
}

/* find all position which data appeared at linked list */
void llFind(LL_t* head, int data)
{
    LL_t* p = head;
    int n = 0;
    while( p ) {
        if(p->data == data) {
            printf("@%d ", n);
        }
        n++;
        p = p->next;
    }
    putchar(10);

}

/* print linked list */
void llPrint(LL_t* head)
{
    LL_t* p = head->next; // skip head
    while( p ) {
        printf( "%d->", p->data );
        p = p->next;
    }
    putchar(10);
}

/* return a reverse linked list */
LL_t* llReverseRet(LL_t* head)
{
    LL_t* newl = (LL_t*)malloc(sizeof(LL_t));
    newl->next = NULL;
    LL_t* p = head->next, * new_node;
    while( p ) {
        new_node = (LL_t*)malloc(sizeof(LL_t));
        new_node->data = p->data;

        new_node->next = newl->next;
        newl->next = new_node;

        p = p->next;
    }
    return newl;
}

/* reverse linked list */
void llReverse(LL_t** head_ref)
{
    LL_t* prev = NULL;
    LL_t* curr = *head_ref;
    LL_t* next = NULL;

    while( curr ) {
        next = curr->next; // save next ptr, next move
        curr->next = prev; // reverse curr ptr
        prev = curr;       // prev move step
        curr = next;       // curr move step
    }
    // head ptr should be first
    (*head_ref)->next = prev ;
    while( prev->next != *head_ref ) {
        prev = prev->next;
    }
    prev->next = NULL;
    // *head_ref = prev;
}

// Drive Code
int main(int argc,const char *argv[])
{
    LL_t* l = llCreate();
    llPush(l, 3);
    llPush(l, 2);
    llPush(l, 1);
    llAppend(l, 5);
    llInsert(l, 4, 4);
    llAppend(l, 5);
    llDelete(l, 4);
    llChange(l, 10, 4);
    llPrint(l);
    llFind(l, 5);
    llReverse(&l);
    llPrint(l);
    llDestroy(&l);
    return 0;
}

