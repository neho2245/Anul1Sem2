#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tema1.h"

extern void INSERT_RIGHT(TList tail, char inscription);
extern void INSERT_LEFT(TList tail, char inscription);

int main ()
{
    TList head = initList();
    INSERT_RIGHT(head, '!');
    INSERT_LEFT(head, 'C');
    INSERT_RIGHT(head, '1');
    MOVE_LEFT(head);
    MOVE_LEFT(head);
    MOVE_LEFT(head);
    WRITE(head, 'a');
    printList(head);
    return 0;
}