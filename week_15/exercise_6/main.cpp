#include <iostream>

int main() {
  std::cout << "2D int array" << std::endl;

  int arr[9];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int value;
      std::cout << "Input value: "; 
      std::cin >> value;
      arr[3 * i + j] = value;
    }
  }
  
  std::cout << std::endl << std::endl;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      std::cout << arr[3 * i + j] << " ";
    }
    std::cout << std::endl;
  }
}