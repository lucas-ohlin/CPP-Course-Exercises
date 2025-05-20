#include "circular_queue.h"
#include <iostream>
#include <cassert>

int main() {
  // create queue
  CircularQueue* q1 = createQueue(4);
  CircularQueue* q2 = createQueue(5);

  assert(q1 != NULL);
  assert(q2 != NULL);

  // write to q1
  assert(writeToQueue(q1, 1));
  assert(writeToQueue(q1, 2));
  assert(writeToQueue(q1, 3));
  assert(countQueue(q1) == 3);

  // write to q2
  assert(writeToQueue(q2, 10));
  assert(writeToQueue(q2, 20));
  assert(writeToQueue(q2, 30));
  assert(writeToQueue(q2, 40));
  assert(countQueue(q2) == 4);

  // read from q1
  int out1;
  assert(readFromQueue(q1, &out1));
  assert(out1 == 1);
  assert(countQueue(q1) == 2);

  // read from q2
  int out2;
  assert(readFromQueue(q2, &out2));
  assert(out2 == 10);
  assert(countQueue(q2) == 3);

  // resize one queue
  assert(resizeQueue(q2, 6));
  assert(countQueue(q2) == 3);

  // make the other empty
  emptyQueue(q1);
  assert(countQueue(q1) == 0);

  destroyQueue(q1);
  destroyQueue(q2);

  std::cout << "Tests passed" << std::endl;
  return 0;
}