#include <iostream>
#include <limits>

static int userInput() {
  int value;
  while (true) {
    std::cout << "Input int between 0 - 255: ";
    if (std::cin >> value && value >= 0 && value <= 255) {
      return value;
    } else {
      std::cout << "Invalid input. Please enter a number between 0 and 255...\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
}

static void convertToBinary(char num) {
  for (int i = 0; i < 8; i++) {
    std::cout << ((num >> i) & 0b1) ? 1 : 0;
  }
  std::cout << std::endl;
}

int main() {
  int value = userInput();
  convertToBinary(value);
}