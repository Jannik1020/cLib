

typedef struct lList LinkedList;

LinkedList * createLinkedList();

int insertFirst(LinkedList * list, void*pdata);

int insertLast(LinkedList * list, void*pdata) ;

void * getFirst (LinkedList * list);

void *getLast(LinkedList * list) ;

void *getNext(LinkedList *list) ;

void removeFirst(LinkedList * list) ;

void deleteList(LinkedList * list) ;