#include <stdlib.h>

typedef struct node{
    struct node * next;
    void * pdata;
}Node;

typedef struct {
    Node *firstElement;
    Node *currentElement;
    Node *lastElement;

}LinkedList;

LinkedList * createLinkedList(){
    LinkedList * ptmp = malloc(sizeof(LinkedList));

    if(ptmp) { // gütliger Pointer
        ptmp->firstElement = NULL;
        ptmp->currentElement = NULL;
        ptmp->lastElement = NULL;
    }

    return ptmp;
}

int insertFirst(LinkedList * list, void*pdata){
    Node * ptmp = malloc (sizeof(Node));
    if(ptmp) {
        ptmp->next = list->firstElement;
        ptmp->pdata = pdata;
        list->firstElement = ptmp;
        if(list->lastElement==NULL){list->lastElement = list->firstElement; }

    }
    return (int)(long)ptmp; // Bei allem außer NULL != 0 wahrscheinlich;
}

int insertLast(LinkedList * list, void*pdata) {
    Node * ptmp = malloc(sizeof(Node));
    if(ptmp){
        ptmp->next = NULL;
        ptmp->pdata = pdata;
        if(list->firstElement == NULL){list->firstElement; } 
        else {list->lastElement->next = ptmp;}
        list->lastElement = ptmp;    }
    return(int)(long)ptmp;
}

void * getFirst (LinkedList * list){ 
    void * ptmp = NULL;

    if(list->firstElement) {
        ptmp = list->firstElement->pdata;
        list->currentElement = list->firstElement;
    }
    return ptmp;
}

void *getLast(LinkedList * list) {
    void * ptmp = NULL;
    
    if(list->lastElement) {
        ptmp = list->lastElement->pdata;
        list->currentElement = list->lastElement;
    }

    return ptmp; 
}

void *getNext(LinkedList *list) {
    void *ptmp = NULL;

    if(list->currentElement) {
        list->currentElement = list->currentElement->next;
        if(list->currentElement){ // curr Elem already next Elem
            ptmp= list->currentElement->pdata;
        }
    }

    return ptmp;
}

void removeFirst(LinkedList * list) {
    if(list->firstElement) {
        Node * ptmp = list->firstElement;
        list->firstElement = ptmp->next;
        free(ptmp);
    }
}

void deleteList(LinkedList * list) {
    while(list->firstElement) removeFirst(list);
    free(list);
}
