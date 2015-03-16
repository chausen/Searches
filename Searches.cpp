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
  for (int i = 0; i != (data_size - 1); ++i) {
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
// Create two variables representing the max and min of the subset of data you are considering; set them to data_size - 1 (max) and 0 (min) to begin with
// Use the standard sort() function to sort the array
// Loop while max =/= min
  // Compute the midpoint: ( max - min ) / 2
  // If the number being sought equals the number at the midpoint, set the boolean to true and return it
  // If it is greater than, set min to midpoint, and recompute the midpoint
  // If it is less than, set max to midpoint, and recompute the midpoint
// Return the boolean (if you get here, it will still be false; the number is not in the array)
bool binary_search(int* data, const int data_size, const int num) {
  bool found = false;
  int min = 0;
  int max = data_size - 1;
  int midpoint(0);
  // Standard library sort requires iterators as arguments; need to put data into a vector and sort the vector
  std::vector<int> data_vector (data, data + max);
  std::sort(data_vector.begin(), data_vector.end());
  while (max != min) {
    midpoint = (max - min) / 2;
    if (num == data_vector[midpoint]) {
      found = true;
      return found;
    }
    else if (num > data_vector[midpoint]) {
      min = midpoint;
    }
    else if (num < data_vector[midpoint]) {
      max = midpoint;
    }
  }
  return found;
}
