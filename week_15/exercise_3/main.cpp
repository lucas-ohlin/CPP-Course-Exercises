#include <iostream>
#include <limits>

static int getUserInput() {
  int value;
  while (true) {
    std::cout << "Enter positive number: ";
    if (std::cin >> value && value >= 0) {
      return value;
    } else {
      std::cout << "Invalid input. Please enter a number.\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
}

int main() {
  int num;
  int total = 0;
  while (true) {
    num = getUserInput();
    std::cout << "Num: " << num << std::endl;
    if (num >= 0) {
      for (int i = 0; i <= num; i++) {
        if (i % 2 == 0) {
          total += i;
        }
      }
      std::cout << "Sum of all values of all even numbers from 0-" << num << " is: " << total;
      break;
    } else {
      std::cout << "Num needs to be positive...\n";
    }
  }
}
