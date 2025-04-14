#include <iostream>
#include <random>

static int randomNum() {
  std::random_device device;
  std::mt19937 rng(device());
  std::uniform_int_distribution<std::mt19937::result_type> dist(0, 99);

  return dist(rng);
}

int main() {
  const int rows = 2;
  const int cols = 3;

  int arr[rows][cols];
  int* pArr = &arr[0][0];

  for (int i = 0; i < rows * cols; ++i) {
    *(pArr + i) = randomNum();
  }

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      std::cout << *(*(arr + i) + j) << " ";
    }
    std::cout << "\n";
  }
}