#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct queueNode {
  int val;
  struct queueNode *next;
} node;

typedef struct {
  node *front, *rear;
} queue;

typedef struct {
  queue *q1, *q2;
} MyStack;

queue *newQueue() {
  queue *q = malloc(sizeof(queue));
  q->front = NULL;
  q->rear = NULL;
  return q;
}

void enQueue(queue *q, int val) {
  node *newq = malloc(sizeof(node));
  newq->val = val;
  newq->next = NULL;
  if (q->rear == NULL) {
    q->front = newq;
    q->rear = newq;
    return;
  }
  q->rear->next = newq;
  q->rear = newq;
}

int deQueue(queue *q) {
  if (q->front == NULL) {
    return -1;
  }

  int delete = q->front->val;
  node *temp = q->front;
  q->front = q->front->next;

  if (q->front == NULL) {
    q->rear = NULL;
  }
  free(temp);
  return delete;
}

bool isEmpty(queue *q) { return (q->front == NULL && q->rear == NULL); }

int queuePeek(queue *q) {
  if (q->front == NULL) {
    return -1;
  }
  while (q->front != NULL) {
    return q->front->val;
  }
  return -1;
}

MyStack *myStackCreate() {
  MyStack *newStack = (MyStack *)malloc(sizeof(MyStack));
  newStack->q1 = newQueue();
  newStack->q2 = newQueue();
  return newStack;
}

void myStackPush(MyStack *obj, int x) {
  enQueue(obj->q2, x);
  while (!isEmpty(obj->q1)) {
    enQueue(obj->q2, deQueue(obj->q1));
  }
  queue *temp = obj->q1;
  obj->q1 = obj->q2;
  obj->q2 = temp;
}

int myStackPop(MyStack *obj) {
  if (isEmpty(obj->q1)) {
    return -1;
  }
  return deQueue(obj->q1);
}

int myStackTop(MyStack *obj) {
  if (isEmpty(obj->q1)) {
    return -1;
  }
  return queuePeek(obj->q1);
}

bool myStackEmpty(MyStack *obj) { return isEmpty(obj->q1); }

void myStackFree(MyStack *obj) { free(obj); }
