#include <iostream>
#include <random>

using namespace std;

static int partOne() {
  char letter;
  cout << "Write a lowercase letter: ";
  cin >> letter;
  // Converts the ascii character to an uppercase version of it
  // works since lowercase characters like "t" have an ascii value 32 lower than their uppercase counterparts
  letter -= 32; 
  cout << "Upper Case: " << letter << endl;
  return 0;
}

static int randomNum() {
  random_device device;
  mt19937 rng(device());
  uniform_int_distribution<mt19937::result_type> dist6(1, 100);

  return dist6(rng);
}

static int partTwo() {
  cout << "Random number 1: " << randomNum() << endl;
  cout << "Random number 2: " << randomNum() << endl;

  return 0;
}

int main() {
  partOne();
  partTwo();
}