#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define EMPTY 0
#define FULL 10000

typedef struct Elem {
	int data;
	struct Elem *next;
}Elem;

typedef struct Queue {
	int count;
	Elem *front;
	Elem *rear;
}Queue;

void init(Queue *q) {
	q->count = 0;
	q->front = NULL;
	q->rear = NULL;
}

int dequeue(Queue *q) {
	int data = q->front->data;
	Queue *temp = q->front;
	q->front = q->front->next;
	q->count--;
	free(temp);
	return data;
}

void enqueue(Queue *q, int data) {
	Elem *temp = (Elem *)malloc(sizeof(Elem));
	temp->data = data;
	temp->next = NULL;
	if(!empty(q)) {
		q->rear->next = temp;
		q->rear = temp;
	} else {
		q->front = q->rear = temp;
	}
	q->count++;
}

int front(const Queue *q) {
	return (q->front->data);
}

int empty(const Queue *q) {
	return (q->count == EMPTY);
}

int full(const Queue *q) {
	return (q->count == FULL);
}

int main(void) {
	/* test */
	Queue a;
	init(&a);
	if(!full(&a)) enqueue(&a, 1);
	if(!full(&a)) enqueue(&a, 2);
	if(!full(&a)) enqueue(&a, 3);

	while(!empty(&a)) {
		printf("Data: %d\n", dequeue(&a));
	}
	return 0;
}