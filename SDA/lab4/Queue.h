#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode{
	Item elem;
	struct QueueNode *next;
}QueueNode;

typedef struct Queue{
	QueueNode *front;
	QueueNode *rear;
	long size;
}Queue;

Queue* createQueue(void){
	// TODO: Cerinta 2
	Queue *q = calloc(1, sizeof(Queue));
	return q;
} 

int isQueueEmpty(Queue *q){
	// TODO: Cerinta 2
	return q == NULL || q->front == NULL || q->rear == NULL;
}

void enqueue(Queue *q, Item elem){
	// TODO: Cerinta 2
	if (q == NULL)
		return;
	QueueNode *node = malloc(sizeof(QueueNode));
	node->elem = elem;
	node->next = NULL;
	if (q->front == NULL) {
		q->front = q->rear = node;
		q->size++;
		return;
	}
	q->rear->next = node;
	q->rear = node;
	q->size++;
}

Item front(Queue* q){
	return q->front->elem;
	// TODO: Cerinta 2

}

void dequeue(Queue* q){
	if (q == NULL || q->front == NULL) {
		return;
	}
	QueueNode *tmp = q->front;
	q->front = q->front->next;
	q->size--;
	if (q->size == 0)
		q->rear = NULL;
	free(tmp);
	// TODO: Cerinta 2

}

void destroyQueue(Queue *q){
	// TODO: Cerinta 2
	while (q->size) {
		dequeue(q);
	}
	free(q);
}

#endif
