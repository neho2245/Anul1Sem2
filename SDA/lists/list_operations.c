#include <stdio.h>
#include <stdlib.h>

typedef int T;

typedef struct node {
    T value;
    struct node* next;
} Node, *Tlist;

Tlist init (T value) {
    Tlist result = (Tlist) calloc(1, sizeof(Tlist));
    result->value = value;
    return result;
}

void iterrateOverList (Tlist list) {
    Tlist itr = list;
    while (itr != NULL) {
        printf("%d ", itr->value);
        itr = itr->next;
    }
    printf("\n");
}

Tlist addElementAtBeginning (Tlist list, T value) {
    Tlist new_list = init(value);
    new_list->next = list;
    return new_list;
}

Tlist addElementAtTheEnd (Tlist list, T value) {
    Tlist new_list = init(value);
    Tlist itr = list;
    while (itr->next != NULL) {
        itr = itr->next;
    }
    itr->next = new_list;
    return list;
}

Tlist addElementOnPos (Tlist list, T value, int position) {
    Tlist new_list = init(value);
    Tlist itr = list;
    int counter = 1;
    if (list == NULL) {
        return list;
    }
    while (itr->next != NULL) {
        counter++;
        if (counter == position)
            break;
        itr = itr->next;
    }
    Tlist tmp = itr->next;
    itr->next = new_list;
    new_list->next = tmp;
    return list;
}

Tlist removeFromBeginning (Tlist list) {
    if (list == NULL) {
        return NULL;
    }
    Tlist tmp = list;
    list = list->next;
    free(tmp);
    return list;
}

Tlist removeFromTheEnd (Tlist list) {
    if (list == NULL || list->next == NULL) {
        return NULL;
    }
    Tlist itr = list;
    while (itr->next->next != NULL) {
        itr = itr->next;
    }
    Tlist tmp = itr->next->next;
    itr->next = NULL;
    free(tmp);
    return list;
}

int main(void) {
    Tlist head = init(10);
    head = addElementAtBeginning(head, 20);
    head = addElementAtBeginning(head, 15);
    head = addElementAtTheEnd(head, 9);
    head = addElementOnPos(head, 72, 2);
    head = removeFromBeginning(head);
    head = removeFromTheEnd(head);
    iterrateOverList(head);
    return 0;
}