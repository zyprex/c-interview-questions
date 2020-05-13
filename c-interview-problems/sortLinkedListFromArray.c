/*
 * 根据数组构造有序链表
 */
#include <stdio.h>
#include <stdlib.h>

/* structure */
typedef struct LinkedList {
    int data;
    struct LinkedList* next;

}LL_t;

/* function declaration */
LL_t* llCreate(void);
void llPrint(LL_t* head);
void llInsArr(LL_t* head, int data);
void llDestroy(LL_t** head_ref);

/* drive code */
int main(int argc, const char *argv[])
{
    int i;
    int arr[10] = {8, 4, 1, 3, 5, 6, 0, 7, 9, 2};
    LL_t* l = llCreate();
    for( i = 0; i < 10; i += 1 ) {
        llInsArr(l, arr[i]);
    }
    llPrint(l);
    llDestroy(&l);
    if(l == NULL)
        puts( "\nDestroy Finished" );
    return 0;
}


/* create a  linked list head */
LL_t* llCreate(void)
{
    LL_t* head = (LL_t*)malloc(sizeof(LL_t));
    if( head == NULL ) {
        puts("malloc failed");
        return NULL;
    }
    head->next = NULL;
    return head;
}

/* insert int data to linked list in order */
void llInsArr(LL_t* head, int data)
{
    if( head == NULL ) return;

    LL_t* new_node = (LL_t*)malloc(sizeof(LL_t));
    new_node->data = data;

    if( head->next == NULL ) {
        // first data, push
        new_node->next = NULL;
        head->next = new_node;
    }
    LL_t* p = head->next;
    if( data < p->data ) {
        // smaller than first data, push
        new_node->next = p;
        head->next = new_node;
        return;
    }
    // find larger data
    while( p ) {
        if( p->next && (p->next->data) > data ) {
            // next data is larger, insert
            new_node->next = p->next;
            p->next = new_node;
            return;
        }
        else if( (p->next == NULL) && ((p->data) < data) ) {
            // this data is the largest one, append
            new_node->next = NULL;
            p->next = new_node;
            return;
        }
        p = p->next;
    }
}

/* print linked list from first data to last */
void llPrint(LL_t* head)
{
    if( head == NULL ) return;

    LL_t* p = head->next; // skip head
    while( p ) {
        printf("%d->", p->data);
        p = p->next;
    }
}

/* delete the entire linked list  */
void llDestroy(LL_t** head_ref)
{
    LL_t* p = *head_ref;
    LL_t* temp;
    while( p ) {
        temp = p->next; // save next pointer
        free(p);        // p is free
        p = temp;       // p to next position
    }
    *head_ref = NULL;   // unref head
}
