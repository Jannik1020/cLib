#include "DoubleLinkedList.h"
#include <stdio.h>

void printDoubleList(DoubleLList * list) {
    for(int i = 0; i < getLength(list); i++) {
        printf("%d, ", *(int *)getElement(list, i));
    }
    printf("\n");
}

int main () {
    int arr []  =  {1,2,3,4,5} ;
    for(int i = 0; i< 5; i++) {
        printf("%p\n", &arr[i]);
    }

    DoubleLList * list = createDoubleLListFromArray(arr, sizeof arr[0], 5);
    printDoubleList(list);
    
}