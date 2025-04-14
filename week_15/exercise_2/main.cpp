#include <iostream>

static bool checkValue(int value) {
  if (value < 0) return false;
  if (value > 255) return false;
  return true;
}

static int cppStyleInput() {
  int value;
  std::cout << "C++ style input.\n";
  std::cout << "Enter int between 0-255: ";
  std::cin >> value;
  std::cout << "Entered int: " << value << std::endl;

  return value;
}

static int cStyleInput() {
  int value;
  printf("C style input.\n");
  printf("Enter int between 0-255: ");
  scanf("%d", &value);
  printf("Entered int: %d\n", value);

  return value;
}

int main() {
  int num;
  bool check = true;
  while (check) {
    num = cppStyleInput();
    if (checkValue(num)) {
      check = false;
    } else {
      std::cout << "\nError: Input isn't between 0-255...\n\n";
    }
  }

  std::cout << "Hexadecimal form of " << num << " is: "; 
  std::cout << std::hex << num << std::dec;
  return 0;
}