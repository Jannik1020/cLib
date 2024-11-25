#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    struct node *pPrev;
    struct node *pNext;
    void *pData;
} Node;

typedef struct doubleLList
{
    Node *firstElement;
    Node *currentElement;
    Node *lastElement;
    int length;

} DoubleLList;

DoubleLList *createDoubleLList()
{
    DoubleLList *list = malloc(sizeof(DoubleLList));

    if (list)
    {
        list->firstElement = NULL;
        list->currentElement = NULL;
        list->lastElement = NULL;
        list->length = 0;
    }

    return list;
}

int getLength(DoubleLList * list) {
    return list->length;
}

void *getNext(DoubleLList *list)
{
    Node *pTmp = NULL;
    if ((list->currentElement))
    {
        if (list->currentElement->pNext)
        {
            list->currentElement = list->currentElement->pNext;

            if (list->currentElement)
            {
                pTmp = list->currentElement->pData;
            }
        }
    }
    return pTmp;
}

void *getPrev(DoubleLList *list)
{
    Node *pTmp = NULL;
    if (list->currentElement && list->currentElement->pPrev)
    {
        list->currentElement = list->currentElement->pPrev;
        if (list->currentElement)
        {
            pTmp = list->currentElement->pData;
        }
    }
    return pTmp;
}

void *getFirst(DoubleLList *list)
{
    Node *pTmp = NULL;
    if (list->firstElement)
    {
        list->currentElement = list->firstElement;
        pTmp = list->currentElement->pData;
    }
    return pTmp;
}
void *getLast(DoubleLList *list)
{
    Node *pTmp = NULL;
    if (list->lastElement)
    {
        list->currentElement = list->lastElement;
        pTmp = list->currentElement->pData;
    }
    return pTmp;
}

void *getElement(DoubleLList *list, int index)
{
    Node *pTmp = NULL;

    if (list->length > 0 && index < list->length)
    {
        if (index < (list->length / 2) || list->length < 3)
        { // in der hinteren Hälfte --> kann von letztem Element iterieren
            list->currentElement = list->firstElement;
            for (int i = 0; i < index; i++)
            {
                list->currentElement = list->currentElement->pNext;
            }
        }
        else
        {
            list->currentElement = list->lastElement;
            for (int i = 0; i < list->length - index - 1; i++)
            {
                list->currentElement = list->currentElement->pPrev;
            }
        }
        pTmp = list->currentElement->pData;
    }

    return pTmp;
}

int insertFirst(DoubleLList *list, void *pData)
{
    Node *pTmp = malloc(sizeof(Node));
    if (pTmp)
    {
        pTmp->pData = pData;
        pTmp->pNext = list->firstElement; // könnte NULL sein
        pTmp->pPrev = NULL;
        if (list->length > 0)
        { // firstElement nicht null;
            list->firstElement->pPrev = pTmp;
        }
        else
        {
            list->lastElement = pTmp;
        }
        list->firstElement = pTmp;
        list->length = list->length + 1;
    }
    return (int)(long)pTmp;
}
int insertLast(DoubleLList *list, void *pData)
{
    Node *pTmp = malloc(sizeof(Node));
    if (pTmp)
    {
        pTmp->pData = pData;
        pTmp->pNext = NULL;
        pTmp->pPrev = list->lastElement;

        if (list->length > 0)
        {
            list->lastElement->pNext = pTmp;
        }
        else
        {
            list->firstElement = pTmp;
        }
        list->lastElement = pTmp;
        list->length = list->length + 1;
    }
    return (int)(long)pTmp;
}
int insertBeforeElement(DoubleLList *list, void *pData, int index)
{
    if (index == 0)
        return insertFirst(list, pData);

    Node *pTmp = malloc(sizeof(Node));
    Node *saveCurrentElement = list->currentElement;

    if (list->length > 0)
    {

        if (index > list->length)
            return (int)(long)pTmp;

        if (index < (list->length / 2) || list->length < 3)
        { // in der hinteren Hälfte --> kann von letztem Element iterieren
            list->currentElement = list->firstElement;

            for (int i = 0; i < index; i++)
            {
                list->currentElement = list->currentElement->pNext;
            }
        }
        else
        {
            list->currentElement = list->lastElement;
            for (int i = 0; i < list->length - index - 1; i++)
            {
                list->currentElement = list->currentElement->pPrev;
            }
        }
        pTmp->pData = pData;
        pTmp->pPrev = list->currentElement->pPrev;
        list->currentElement->pPrev = pTmp;

        pTmp->pNext = list->currentElement;
        if (pTmp->pPrev)
            pTmp->pPrev->pNext = pTmp;
        list->length = list->length + 1;
    }
    else
    {
        insertFirst(list, pData);
    }
    list->currentElement = saveCurrentElement;

    return (int)(long)pTmp;
}

void removeFirst(DoubleLList *list)
{
    if (list->firstElement)
    {
        Node *pTmp = list->firstElement;
        list->firstElement->pPrev = NULL;
        list->firstElement = list->firstElement->pNext;

        free(pTmp);
        list->length-=1;
    }
}
void removeLast(DoubleLList *list)
{
    if (list->lastElement)
    {
        Node *pTmp = list->lastElement;
        list->lastElement = list->lastElement->pPrev;
        list->lastElement->pNext = NULL;
        free(pTmp);
        list->length-=1;
    }
}
void removeElement(DoubleLList *list, int index)
{
    if (index == 0)
        removeFirst(list);
    if (index == list->length - 1)
        removeLast(list);
    if (index > list->length)
        return;

    if (list->length > 0)
    {

        if (index < (list->length / 2) || list->length < 3)
        { // in der hinteren Hälfte --> kann von letztem Element iterieren
            list->currentElement = list->firstElement;

            for (int i = 0; i < index; i++)
            {
                list->currentElement = list->currentElement->pNext;
            }
        }
        else
        {
            list->currentElement = list->lastElement;
            for (int i = 0; i < list->length - index - 1; i++)
            {
                list->currentElement = list->currentElement->pPrev;
            }
        }
        Node *pTmp = list->currentElement;
        list->currentElement->pPrev->pNext = list->currentElement->pNext;
        list->currentElement->pNext->pPrev = list->currentElement->pPrev;
        free(pTmp);
        list->length-=1;
    }
}
void deleteList(DoubleLList *list){
    while(list->firstElement) {
        printf("%d\n" ,*(int*) list->firstElement->pData);
        removeFirst(list);
    }
    free(list);
}