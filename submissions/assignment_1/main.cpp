#include <iostream>
#include <stddef.h>
#include <stdlib.h>
#include <cassert>

struct Node {
  int data;
  Node* next;
};

struct CircularQueue {
  Node* old_data;     
  Node* new_data;    
  size_t size; 
  size_t count;
  Node* head;  
};

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
  
  while (q->count > newSize) {
    int tmp;
    readFromQueue(q, &tmp);
  }

  q->size = newSize;
  return 1;
}

int main() {
  // create queue
  CircularQueue* q = createQueue(5);
  assert(q != NULL);
  
  // count queue
  assert(countQueue(q) == 0);

  // write to queue
  assert(writeToQueue(q, 10));
  assert(writeToQueue(q, 20));
  assert(writeToQueue(q, 30));
  assert(countQueue(q) == 3);

  // read from queue
  int val;
  assert(readFromQueue(q, &val));
  assert(val == 10);
  assert(countQueue(q) == 2);

  // queue overflow  
  assert(writeToQueue(q, 40));
  assert(writeToQueue(q, 50));
  assert(writeToQueue(q, 60));
  assert(writeToQueue(q, 70));
  assert(countQueue(q) == 5);

  // if queue is full
  assert(isQueueFull(q));

  // resize queue
  assert(resizeQueue(q, 4));
  assert(countQueue(q) == 4);

  // empty queue 
  emptyQueue(q);
  assert(countQueue(q) == 0);

  destroyQueue(q);  
  std::cout << "Tests passed" << std::endl;
  return 0;
}