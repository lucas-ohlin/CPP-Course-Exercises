#include <iostream>
#include <random>
#include <stdlib.h>
#include <ctime>

static int lcgRandom(int min = 0, int max = 99) {
  // std::srand(std::time(nullptr));
  return rand() % (max - min + 1) + min;
}

static int cryptoRandom(int min = 0, int max = 99) {
  std::random_device device;
  std::mt19937 rng(device());
  std::uniform_int_distribution<std::mt19937::result_type> dist(min, max);

  return dist(rng);
}

static void drawLine(int amount) {
  for (int i = 0; i < amount; i++) {
    std::cout << "*";
  }
  std::cout << std::endl;
}

static void drawLine_text(const std::string& text, int amount) {
  for (int i = 0; i < amount; i++) {
    std::cout << "*";
  }
  std::cout << text;
  for (int i = 0; i < amount; i++) {
    std::cout << "*";
  }
  std::cout << std::endl;
}

int main() {
  int randomNum = cryptoRandom();
  int guess;
  int tries = 0;
  std::cout << randomNum << std::endl;

  drawLine(16);
  drawLine_text("Game Started", 2);
  drawLine(16);

  while (true) {
    std::cout << std::endl << "Guess the number (0-99): ";
    std::cin >> guess;
    if (guess == randomNum) {
      std::cout << std::endl << "Congrats, " << randomNum << " was correct!";
      break;
    } 
    if (guess < randomNum) {
      std::cout << "Your guess was too small!" << std::endl;
    }
    if (guess > randomNum) {
      std::cout << "Your guess was too big!" << std::endl;
    }
    if (tries == 10) {
      std::cout << std::endl << "You ran out of tries!";
      break;
    }
    else {
      tries += 1;
      std::cout << "Wrong guess, " << 11 - tries << " tries left.";
    }
  }
}