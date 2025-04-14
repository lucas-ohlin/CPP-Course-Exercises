#include <iostream>
// https://en.cppreference.com/w/cpp/string/basic_string/getline

int main() {
  std::string userInput;
  std::cout << "Input: ";
  std::getline(std::cin, userInput);  

  for (int i = 0; i < userInput.length() / 2; ++i) {
    char temp = userInput[i];
    userInput[i] = userInput[userInput.length() - 1 - i];
    userInput[userInput.length() - 1 - i] = temp;
  }

  std::cout << "Reversed string: " << userInput << std::endl;
}