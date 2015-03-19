/* Author: Clay Hausen
 * Last Modified: 3/19/2015
 *
 * DESCRIPTION:
 * C++ Implementations of search algorithms.
 * Currently Supports:
 * Linear Search (ints only)
 * Binary Search (ints only)
*/ 

#include <algorithm>  // std::sort
#include <vector>     // std::vector


/* ---------- METHOD DESCRIPTION ----------
 * Takes an array of integers, the size of the array, and an integer to be found as parameters.
 * Sequentially searches the array
 * Returns true if the integer is found, and false otherwise. */
// ---------- PSUEDOCODE ----------
// Iterate from the first element of the array, to the last
  // If the current element = the sought element, return true
// The end of the array was reached: return false
bool linear_search(int* data, const int data_size, const int num) {
  for (int i = 0; i != data_size; ++i) {
    if (data[i] == num) return true;
  }
  return false;
}

/* ---------- METHOD DESCRIPTION ----------
 * Takes an array of integers, the size of the array, and an integer to be found as parameters.
 *  Uses binary search on the array
 *  Returns true if the integer is found, and false otherwise. */
// ---------- PSUEDOCODE ----------
// Create a boolean representing whether the number was found, and set it to false
// Store the beginning and end of the array in variables (min & max)
// Use the standard sort() function to sort the array
// Loop while max =/= min
  // Compute the midpoint: ( max + min ) / 2
  // If the number being sought equals the number at the midpoint, set the boolean to true and return it
  // If it is greater than, look at the subarray from midpoint + 1 to max
  // If it is less than, look at the subarray from min to midpoint - 1
// Return the boolean (if you get here, it will still be false; the number is not in the array)
bool binary_search(int* data, const int data_size, const int num) {
  bool found = false;
  int min(0);
  int max(data_size - 1);
  int midpoint(0);
  
  // Standard library sort requires iterators as arguments; need to put data into a vector and sort the vector
  std::vector<int> data_vector (data, data + data_size);
  std::sort(data_vector.begin(), data_vector.end());

  // Binary Search Algorithm
  while (max >= min) {
    midpoint = (max + min) / 2;
    if (num == data_vector[midpoint]) {
      found = true;
      return found;
    }
    else if (data_vector[midpoint] < num) {
      min = midpoint + 1; // look at the larger half of the array
    }
    else if (num < data_vector[midpoint]) {
      max = midpoint - 1; // look at the smaller half of the array
    }
  }
  
  return found;
}
