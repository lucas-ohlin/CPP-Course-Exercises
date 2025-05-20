#include "circular_queue.h"
#include <cassert>

CircularQueue* createQueue(size_t size) {
  if (size <= 3) return NULL;

  CircularQueue* q = (CircularQueue*)malloc(sizeof(CircularQueue));
  if (!q) return NULL;

  // create all nodes and link them 
  Node* firstNode = (Node*)malloc(sizeof(Node));
  if (!firstNode) {
    free(q);
    return NULL;
  }

  Node* current = firstNode;

  // create remaining nodes
  for (size_t i = 1; i < size; i++) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
      // cleans up already alocated nodes
      Node* temp = firstNode;
      Node* next;
      while (temp) {
        next = temp->next;
        free(temp);
        temp = next;
        if (temp == firstNode) break;
      }
      free(q);
      return NULL;
    }
    current->next = newNode;
    current = newNode;
  }

  current->next = firstNode;

  q->size = size;
  q->count = 0;
  q->head = firstNode;
  q->old_data = q->new_data = NULL;

  return q;
}

void emptyQueue(CircularQueue* q) {
  if (!q) return;
  q->count = 0;
  q->old_data = q->new_data = NULL;
}

void destroyQueue(CircularQueue* q) {
  if (!q) return;

  emptyQueue(q);

  if (q->head) {
    Node* current = q->head;
    Node* start = current;
    Node* next;
    do {
      next = current->next;
      free(current);
      current = next;
    } while (current != start);
  }

  free(q);
}

int writeToQueue(CircularQueue* q, int value) {
  if (!q) return 0;

  // if empty use the first alocated node
  if (q->count == 0) {
    q->old_data = q->new_data = q->head;
    q->old_data->data = value;
    q->count++;
    return 1;
  }

  // if full overwrite oldest element
  if (q->count == q->size) {
    q->old_data = q->old_data->next;
  } else {
    q->count++;
  }

  // set the new value in the next node after new_data
  q->new_data = q->new_data->next;
  q->new_data->data = value;

  return 1;
}

int readFromQueue(CircularQueue* q, int* out) {
  if (!q || q->count == 0) return 0;

  *out = q->old_data->data;

  // update queue pointers
  if (q->old_data == q->new_data) {
    q->old_data = q->new_data = NULL;
  } else {
    q->old_data = q->old_data->next;
  }

  q->count--;
  return 1;
}

size_t countQueue(const CircularQueue* q) {
  return q ? q->count : 0;
}

int isQueueFull(const CircularQueue* q) {
  return q && q->count == q->size;
}

int resizeQueue(CircularQueue* q, size_t newSize) {
  if (!q || newSize <= 3) return 0;

  if (newSize == q->size) return 1;

  int* tempData = (int*)malloc(sizeof(int) * (newSize));
  if (!tempData) return 0;

  size_t itemsToCopy = (q->count < newSize) ? q->count : newSize;

  int val;

  size_t toSkip = q->count - itemsToCopy;
  for (size_t i = 0; i < toSkip; ++i) {
    readFromQueue(q, &val); 
  }

  for (size_t i = 0; i < itemsToCopy; ++i) {
    readFromQueue(q, &tempData[i]);
  }

  if (q->head) {
    Node* current = q->head;
    Node* start = current;
    Node* next;
    do {
      next = current->next;
      free(current);
      current = next;
    } while (current != start);
  }

  Node* firstNode = (Node*)malloc(sizeof(Node));
  if (!firstNode) {
    free(tempData);
    return 0;
  }
  Node* current = firstNode;
  for (size_t i = 1; i < newSize; i++) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
      // clean up
      Node* temp = firstNode;
      Node* next;
      do {
        next = temp->next;
        free(temp);
        temp = next;
      } while (temp && temp != firstNode);
      free(tempData);
      return 0;
    }
    current->next = newNode;
    current = newNode;
  }
  current->next = firstNode;

  // write stored data into new queue
  q->head = firstNode;
  q->size = newSize;
  q->count = 0;
  q->old_data = q->new_data = NULL;

  for (size_t i = 0; i < itemsToCopy; i++) {
    writeToQueue(q, tempData[i]);
  }

  free(tempData);
  return 1;
}
