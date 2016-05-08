#include <iostream>

int number [10];

void fill_array(int first_value, int increment) {
  number[0] = first_value;
  std::cout<< number[0];
  for (int i = 1; i < 10; i++) {
    number[i] = number[i-1] + increment;
    std::cout<< number[i];
  }
}

int main() {
  fill_array(4, 2);
}
