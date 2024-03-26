#ifndef STACK_H_
#define STACK_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode{
	Item elem;
	struct StackNode *next;
} StackNode;

typedef struct Stack{
	StackNode* head;  // Varful stivei
	long size; // Numarul de elemente din stiva
} Stack;

Stack* createStack(void){
	// TODO: Cerinta 1
	Stack *stack = (Stack *) malloc(sizeof(Stack));
	stack->head = NULL;
	stack->size = 0;
	return stack;
}

int isStackEmpty(Stack* stack){
	// TODO: Cerinta 1
	if (stack == NULL || stack->head == NULL)
		return 1;
	else {
		return 0;
	}
}

void push(Stack *stack, Item elem){
	// TODO: Cerinta 1
	if (stack == NULL) {
		return;
	}
	StackNode *node = malloc(sizeof(StackNode));
	node->elem = elem;
	node->next = stack->head;
	stack->head = node;
	stack->size++;
}

Item top(Stack *stack){	
	// TODO: Cerinta 1
	if (stack == NULL || stack->head == NULL) {
		return -1;
	}
	return stack->head->elem;
} 

void pop(Stack *stack){
	// TODO: Cerinta 1
	if (stack == NULL || stack->head == NULL) {
		return;
	}
	StackNode *tmp = stack->head;
	stack->head = stack->head->next;
	stack->size--;
	free(tmp);
}

void destroyStack(Stack *stack){
	// TODO: Cerinta 1
		while (stack->size != 0) {
		pop(stack);
	}
	free(stack);
}

#endif 
