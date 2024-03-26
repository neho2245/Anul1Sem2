#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char value;
    struct node* next;
} Node;

typedef struct {
    int size;
    Node* top;
} Stack;

Node* createNode (char op) {
    Node* new = calloc(1, sizeof(Node));
    new->value = op;
    return new;
}

Stack* push (Stack* stack, char op) {
    if (stack == NULL)
        return NULL;
    Node* node = createNode(op);
    node->next = stack->top;
    stack->top = node;
    stack->size++;
    return stack;
}

Stack* pop (Stack* stack) {
    stack->top = stack->top->next;
    stack->size--;
    return stack;
}

char top (Stack* stack) {
    return stack->top->value;
}

int calPoints(char** operations, int operationsSize) {
    Stack* stack = calloc(1, sizeof(Stack));
}

int main () {
    char* test = calloc(10, sizeof(char));
    fscanf(stdin, "%s", test);
    Stack* stack = calloc(1, sizeof(Stack));
    for (int i = 0; i < strlen(test); i++) {
        if (test[i] == 'C') {
            stack = pop(stack);
        } else if (test[i] == 'D') {
            int num = (top(stack) - '0');
            num = num * 2;
            stack = push(stack, (char)num +'0');
        } else if (test[i] == '+') {
            Node* tmp = stack->top;
            char val = tmp->value; 
            pop(stack);
            int newElement = (int)(tmp->value - '0') + (int)(top(stack) - '0');
            push(stack, val);
            push(stack, (char)newElement + '0');
        } else {
            stack = push(stack, test[i]);
        }
    }
    int sum = 0;
    while (stack->top != NULL) {
        sum += (int)(top(stack) - '0');
        stack = pop(stack);
    }
    printf("%d\n", sum);
}