#include <iostream>

struct person_t {
  int id;
  int age;
  std::string name;
};

int main() {
  person_t people[3];

  for (int i = 0; i < 3; i++) {
    std::cout << "Enter data on person: " << i << std::endl;
    people[i].id = i;
    
    std::cout << "Name: ";
    std::cin >> people[i].name;

    std::cout << "Age: ";
    std::cin >> people[i].age;
    std::cout << "\n";
  }

  for (int i = 0; i < 3; ++i) {
    std::cout << "Person: " << i + 1 << " ID=" << people[i].id
              << ", Age=" << people[i].age
              << ", Name=" << people[i].name << "\n";
  } 
}