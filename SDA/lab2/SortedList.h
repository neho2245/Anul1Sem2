#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include <stdlib.h>
#include <assert.h>

/*
    IMPORTANT!

    As we stick to pure C, we cannot use templates. We will just asume
    some type T was previously defined.
*/

// -----------------------------------------------------------------------------

typedef struct node {
    T value;
    struct node* next;
} TNode, *TSortedList;

// TODO : Cerința 1 & Cerința 2

TSortedList create(T value) {
    // TODO (se va completa la Cerința 2)
    TSortedList list = calloc(1, sizeof(TNode)); // grija la sizeof (trebuie size de structura in sine)
    list->value = value;
    list->next = NULL;  
    return list;
}

int isEmpty (TSortedList list) {
    if (list == NULL) {
        return 1;
    }
    return 0;
}

int contains (TSortedList list, T value) {
    TSortedList itr = list;
    while (itr != NULL) {
        if (itr->value == value) {
            return 1;
        }
        itr = itr->next;
    }
    return 0;
}

TSortedList insert (TSortedList list, T value) {
    TSortedList itr = list;
    TSortedList prev = NULL;
    TSortedList node = create(value);
    if (list == NULL) {
        return node;
    }
    while (itr != NULL && itr->value < value) {
        prev = itr;
        itr = itr->next;
    }
    if (prev == NULL) {
        node->next = itr;
        list = node;
        return list;
    }
    node->next = itr;
    prev->next = node;
    return list;
}

TSortedList deleteOnce (TSortedList list, T value) {
    TNode* itr = list;
    TNode* prev = NULL;
    if (itr == NULL) {
        return NULL;
    }
    while (itr != NULL && itr->value != value) {
        prev = itr;
        itr = itr->next;
    }
    // GENERAL CASE
    if (itr == NULL) {
        prev->next = NULL;
        return list;
    }
    prev->next = itr->next;
    free(itr);
    return list;
}

long int length (TSortedList list) {
    TSortedList itr = list;
    long int counter = 0;
    while (itr != NULL) {
        counter++;
        itr = itr->next;
    }
    return counter;
}

unsigned int getNth (TSortedList list, unsigned int N) {
    int counter = 1;
    TNode* itr = list;
    while (itr != NULL) {
        if (counter == N) {
            return itr->value;
        }
        counter++;
        itr = itr->next;    
    }
    return 0;
}

TSortedList freeTSortedList (TSortedList list) {
    TNode* itr = list;
    TNode* prev = NULL;
    while (itr != NULL) {
        prev = itr;
        itr = itr->next;
        free(prev);
    }
    return NULL;
}

#endif
