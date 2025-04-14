#include <iostream>
#include <cmath>
#include <limits>

static int userInput() {
  int value;
  while (true) {
    std::cout << "Input int between 2 - 10 000: ";
    if (std::cin >> value && value >= 2 && value <= 10000) {
      return value;
    } else {
      std::cout << "Invalid input. Please enter a number between 2 and 10 000...\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
}

int main() {
  int value = userInput();
  bool isPrime = true;
  for (int i = 2; i <= sqrt(value); i++) {
    if (value % i == 0) {
      isPrime = false;
      break;
    }
  }

  if (isPrime) {
    std::cout << value << " : is prime.";
  } else {
    std::cout << value << " : is not prime.";
  }
}