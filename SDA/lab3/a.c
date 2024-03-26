#include <stdio.h>
#include <stdlib.h>
#include "DoubleLinkedList.h"

typedef char Item;

int main() {
    List* list = createList();
    Item a = 'a';
    Item b = 'b';
    Item c = 'c';
    Item d = 'd';
    insertAt(list, a, 0);
    insertAt(list, b ,1);
    printList(list);
    deleteOnce(list, a);
    deleteOnce(list, b);
    destroyList(list);
}