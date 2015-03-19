/* Author: Clay Hausen
 * Last Modified: 3/19/2015
 *
 * DESCRIPTION:
 * C++ Implementations of search algorithms.
 * Currently Supports:
 * Linear Search (ints only)
 * Binary Search (ints only)
*/ 

#include "Searches.h"
#include <iostream> // std::cin, std::cout, std::endl
// #include <ctime>    // clock

int main(int argc, char* argv[]) {

  int datum(0);         // stores tokens from the input stream
  int counter(0);       // used for parsing the input
  int n(0);             // number of integers input array
  int s(0);             // number of elements to search for
  int* input_elements;  // integers to be searched
  int* search_elements; // integers to be searched for
  
  
  // Read the input to populate the array
  std::cin >> n >> s;

  // Dynamically allocate arrays for input and search elements
  input_elements = new int[n];
  search_elements = new int[s];

  // Populate the arrays
  for (int i = 0; i != n; ++i) { std::cin >> input_elements[i]; }
  for (int i = 0; i != s; ++i) { std::cin >> search_elements[i]; }
  
  
  // Iterate through search_elements, output 'Yes' if found, 'No' otherwise
  std::cout << "Linear Search: " << std::endl;
  for (int i = 0; i != s; ++i) {
    std::cout << (linear_search(input_elements, n, search_elements[i]) ? "Yes" : "No") << std::endl;
  }

  std::cout << "Binary Search: " << std::endl;
  for (int i = 0; i != s; ++i) {
    std::cout << (binary_search(input_elements, n, search_elements[i]) ? "Yes" : "No") << std::endl;
  }


  /* ---------------------------------- USED FOR MEASURING RUN-TIME ----------------------------------  
  double ls_times[100] = {};
  double bs_times[100] = {};
  double bsps_times[100] = {};
  clock_t start, finish;
  double elapsed_time;
  bool ls_result;
  bool bs_result;
  
  // Iterate through search_elements, output 'Yes' if found, 'No' otherwise
  std::cout << "Linear Search: " << std::endl;
  for (int i = 0; i != s; ++i) {

    start = clock();
    ls_result = linear_search(input_elements, n, search_elements[i]);
    finish = clock();
    elapsed_time = (double)(finish - start)/CLOCKS_PER_SEC;
    ls_times[i] = elapsed_time;

    std::cout <<  (ls_result ? "Yes" : "No") << std::endl;
  }
  
  
  std::cout << "Binary Search: " << std::endl;
  for (int i = 0; i != s; ++i) {

    start = clock();
    bs_result = binary_search(input_elements, n, search_elements[i], elapsed_time);
    finish = clock();
    bsps_times[i] = elapsed_time;
    elapsed_time = (double)(finish - start)/CLOCKS_PER_SEC;
    bs_times[i] = elapsed_time;
    
    std::cout << (bs_result ? "Yes" : "No") << std::endl;
  }

    
  // Sum up & average the run time for each search
  double ls_total(0);
  double bs_total(0);
  double bsps_total(0);
  double ls_average(0);
  double bs_average(0);
  double bsps_average(0);
  
  for (int i = 0; i != s; ++i) {
    ls_total += ls_times[i];
    bs_total += bs_times[i];
    bsps_total += bsps_times[i];
  }
  ls_average = ls_total / s;
  bs_average = bs_total / s;
  bsps_average = bsps_total / s;
  
  std::cout << "Linear Search Time: " << ls_average << " (s)" << std::endl;
  std::cout << "Binary Search Time: " << bs_average << " (s)" << std::endl;
  std::cout << "Binary Search (Pre-Sorted) Time: " << bsps_average << " (s)" << std::endl;  
  ------------------------------------------------------------------------------------------------------*/
  
  // Clean up
  delete input_elements;
  delete search_elements;
  
  return 0;
}




