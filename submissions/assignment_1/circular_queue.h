#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stddef.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

typedef struct CircularQueue {
  Node* old_data;
  Node* new_data;
  size_t size;
  size_t count;
  Node* head;
} CircularQueue;

CircularQueue* createQueue(size_t size);
void destroyQueue(CircularQueue* q);
void emptyQueue(CircularQueue* q);
int writeToQueue(CircularQueue* q, int value);
int readFromQueue(CircularQueue* q, int* out);
size_t countQueue(const CircularQueue* q);
int isQueueFull(const CircularQueue* q);
int resizeQueue(CircularQueue* q, size_t newSize);

#endif
