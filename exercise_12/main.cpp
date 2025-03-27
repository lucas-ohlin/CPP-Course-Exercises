#include <iostream>
#include <random>

static int randomNum() {
  std::random_device device;
  std::mt19937 rng(device());
  std::uniform_int_distribution<std::mt19937::result_type> dist(0, 99);

  return dist(rng);
}

static void sortAscending(int* arr, int size) {
  for (int* pArr = arr; pArr < arr + size; ++pArr) {
    for (int* j = pArr + 1; j < arr + size; ++j) {
      if (*pArr > *j) {
        int temp = *pArr;
        *pArr = *j;
        *j = temp;
      }
    }
  }
}

int main() {
  int arr[10];
  for (int* pArr = arr; pArr < arr + 10; ++pArr) {
    *pArr = randomNum();
  }

  std::cout << "Unsorted list:" << std::endl;
  for (int* pArr = arr; pArr < arr + 10; ++pArr) {
    std::cout << *pArr << " ";
  }

  sortAscending(arr, 10);
  std::cout << "\n\nSorted list (ascending):\n";
  for (int* pArr = arr; pArr < arr + 10; ++pArr) {
    std::cout << *pArr << " ";
  }
}