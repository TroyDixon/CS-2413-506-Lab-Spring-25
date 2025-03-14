#include <memory.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct {
  int top;
  int size;
  int stack_arr[MAX_SIZE];
} stack;

typedef struct {
  stack *s1;
  stack *s2;
} MyQueue;

stack *newStack() {
  stack *s = malloc(sizeof(stack));
  s->top = -1;
  s->size = -1;
  return s;
}

bool myStackEmpty(stack *newStack) {
  if (newStack->top == -1) {
    return true;
  }
  return false;
}

bool myStackFull(stack *Stack) {
  if (Stack->top == Stack->size - 1) { // "is top last element put in"
    return true;
  }
  return false;
}

void push(stack *newStack, int val) {
  if (myStackFull(newStack)) {
    return;
  }
  newStack->stack_arr[++newStack->top] = val;
  return;
}

int pop(stack *Stack) {
  if (myStackEmpty(Stack)) {
    return -1;
  }
  int temp = Stack->stack_arr[Stack->top--];
  return temp;
}

void enqueue(MyQueue *obj, int x) { push(obj->s1, x); }

int dequeue(MyQueue *obj) {
  if (myStackEmpty(obj->s2)) {
    while (myStackEmpty(obj->s1) == false) {
      push(obj->s2, pop(obj->s1));
    }
  }

  int temp = pop(obj->s2);
  return temp;
}

int peek(MyQueue *obj) {
  if (myStackEmpty(obj->s2)) {
    return obj->s1->stack_arr[0];
  }
  return obj->s2->stack_arr[obj->s2->top];
}

MyQueue *myQueueCreate() {
  MyQueue *newQueue = (MyQueue *)malloc(sizeof(MyQueue));
  newQueue->s1 = newStack();
  newQueue->s2 = newStack();

  return newQueue;
}

void myQueuePush(MyQueue *obj, int x) { enqueue(obj, x); }

int myQueuePop(MyQueue *obj) { return dequeue(obj); }

int myQueuePeek(MyQueue *obj) { return peek(obj); }

bool myQueueEmpty(MyQueue *obj) {
  return (myStackEmpty(obj->s1) && myStackEmpty(obj->s2));
}

void myQueueFree(MyQueue *obj) { free(obj); }
