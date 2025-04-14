#include <iostream>
#include <random>

using namespace std;

static int randomNum() {
  random_device device;
  mt19937 rng(device());
  uniform_int_distribution<mt19937::result_type> dist6(1, 100);

  return dist6(rng);
}

static int sortDescending(int arr[], int size) {
  int temp;
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      if (arr[i] < arr[j]) {
        temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
      }
    }
  } 
  return 0;
}

static int sortAscending(int arr[], int size) {
  int temp;
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      if (arr[i] > arr[j]) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  } 
  return 0;
}

/**
 * @brief Randomly generates 10 numbers and sets them as the value
 * in a an integer element list.
 * 
 * @return int 
 */
int main() {
  int arr[10];
  for (int i = 0; i < 10; i++) {
    arr[i] = randomNum();
  } 

  cout << "Unsorted list:" << endl;
  for (int j = 0; j < 10; j++) {
    cout << arr[j] << " ";
  }

  sortDescending(arr, 10);
  cout << endl << endl;
  cout << "Sorted list (decending):" << endl;
  for (int j = 0; j < 10; j++) {
    cout << arr[j] << " ";
  }

  sortAscending(arr, 10);
  cout << endl << endl;
  cout << "Sorted list (ascending):" << endl;
  for (int j = 0; j < 10; j++) {
    cout << arr[j] << " ";
  }
}