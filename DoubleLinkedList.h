typedef struct doubleLList DoubleLList;
DoubleLList * createDoubleLList();

int getLength(DoubleLList * list);
void *getNext(DoubleLList *list);

void *getPrev(DoubleLList *list);

void *getFirst(DoubleLList *list);

void *getLast(DoubleLList *list);

void *getElement(DoubleLList *list, int index);
int insertFirst(DoubleLList *list, void *pData);
int insertLast(DoubleLList *list, void *pData);
int insertBeforeElement(DoubleLList *list, void *pData, int index);

void removeFirst(DoubleLList *list);
void removeLast(DoubleLList *list);
void removeElement(DoubleLList *list, int index);

void deleteList(DoubleLList *list);