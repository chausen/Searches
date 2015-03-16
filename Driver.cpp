#include "Searches.h"
#include <iostream>

int main(int argc, char* argv[]) {

  int datum(0);
  int counter(0);
  int current_int(0);
  int input_size(0);
  int X;
  int* data;

  
  
  // Read the input to populate the data array
  while (std::cin >> datum) {
    ++counter;
    switch (counter) {
    case 1: // The first integer gives the number of integers
      input_size = datum;
    case 2: // The second integer gives the number to search for
      X = datum;
      data = new int[input_size];
    default: // After counter has been incremented to 3, the rest of the input populates the area
      data[counter - 3] = datum;
    }
  }

  std::cout << "Input Size: " << input_size << std::endl;
  std::cout << "X: " << X << std::endl;
  std::cout << "Data: "; for (int i = 0; i != input_size; ++i) {std::cout << data[i] << " ";} std::cout << std::endl;
  std::cout << "Linear Search Results for " << X << ": " << linear_search(data, input_size, X) << std::endl;
  std::cout << "Binary Search Results for " << X << ": " << binary_search(data, input_size, X) << std::endl;

  delete data;
  
  return 0;
}
