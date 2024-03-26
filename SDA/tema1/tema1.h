#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// header file for tema1

// defining structure for a circurlar doubly linked list with sentinel

typedef struct node {
    char inscription;
    struct node *next;
    struct node *prev;
} Node, *TDoubleList;

typedef struct list {
    TDoubleList head;
    TDoubleList current;
} *TList;

// initialize list

TDoubleList createNode (char c) {
    TDoubleList node = calloc(1, sizeof(struct node));
    node->inscription = c;
    return node;
}

TList initList () {
    TList list = calloc(1, sizeof(struct list));
    list->head = calloc(1, sizeof(struct node));
    list->current = createNode('#');
    list->head->next = list->current;
    list->head->prev = list->current;
    list->current->prev = list->head;
    list->current->next = list->head;
    return list;
}

void INSERT_LEFT (TList list, char inscription) {
    TDoubleList node = createNode(inscription);
    if (list->head->next == list->current) {
        printf("ERROR\n");
        free(node);
        return;
    }
    node->next = list->current;
    node->prev = list->current->prev;
    list->current->prev->next = node;
    list->current->prev = node;
    list->current = node;
}

void INSERT_RIGHT (TList list, char inscription) {
    TDoubleList node = createNode(inscription);
    node->prev = list->current;
    node->next = list->current->next;
    list->current->next->prev = node;
    list->current->next = node;
    list->current = node; 
}

void MOVE_RIGHT (TList list) {
    //mechanic is in the last wagon
    if (list->current->next == list->head) {
        INSERT_RIGHT(list, '#');
    } else {
        list->current = list->current->next;
    }
}

void MOVE_LEFT (TList list) {
    //mechanic is in the first wagon
    if (list->current->prev == list->head) {
        list->current = list->current->prev->prev;
    } else {
        list->current = list->current->prev;
    }
}

void WRITE (TList list, char newInscription) {
    list->current->inscription = newInscription;
}

void printList (TList list) {
    TDoubleList itr = list->head->next;
    while (itr != list->head) {
        if (itr == list->current) {
            printf("|%c| ", itr->inscription);
        } else {
            printf("%c ", itr->inscription);
        }
        itr = itr->next;
    }
}