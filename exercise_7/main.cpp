#include <iostream>

int main() {
  std::cout << "Following ints between 1-1000 ends with 7:" << std::endl;
  for (int i = 0; i < 1000; i++) {
    if (i % 10 == 7) {
      std::cout << i << " ";
    }
  }
}