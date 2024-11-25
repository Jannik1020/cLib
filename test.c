#include "DoubleLinkedList.h"
#include <stdio.h>

void printDoubleList(DoubleLList * list) {
    for(int i = 0; i < getLength(list); i++) {
        printf("%d, ", *(int *)getElement(list, i));
    }
    printf("\n");
}

int main () {
    DoubleLList * list = createDoubleLList();

    int numbers0 [] = {};
    int numbers1 [] = {0};
    int numbers2 [] = {0,1};
    int numbers3 [] = {0,1,2};
    int numbers9 [] = {0,1,2,3,4,5,6,7,8};

    for(int i = 0; i < 5; i++) {
        insertLast(list, &numbers9[i]);
    }
    printDoubleList(list);
    DoubleLList * list1 = createDoubleLList();

    int n = 60;
    insertBeforeElement(list, &n, 5);

    printDoubleList(list);

    for(int i = 0; i < 9; i++) {
        insertFirst(list1, &numbers9[i]);
    }
    printDoubleList(list1);

    printf("%d\n", *(int*) getFirst(list1));
    printf("%d\n", *(int*) getLast(list1));
    printf("%d\n", *(int*) getPrev(list1));
    printf("%d\n", *(int*) getNext(list1));
    printf("%d\n", *(int*) getLast(list1));
    printDoubleList(list1);
    removeFirst(list1);
    printDoubleList(list1);
    removeLast(list1);
    printDoubleList(list1);
    removeElement(list1, 3);
    printDoubleList(list1);
    deleteList(list1);
    
}