#include <vector>

// A naive sorting algorithm with a time complexity of O(n^2). 
// Sorts array in place and is stable.
std::vector<int> bubbleSort(std::vector<int> arr) {
  int n = arr.size();
  for (int i = n - 1; i >= 0; i--){
    bool swapped = false;
    for (int j = 0; j < i; j++){
      if (arr[j] > arr[j + 1]) {
        std::swap(arr[j], arr[j + 1]);
        swapped = true;
      }
    }
    if (!swapped) return arr;
  }
  return arr;
}

std::vector<int> selectionSort(std::vector<int> arr) {
}

std::vector<int> insertionSort(std::vector<int> arr) {
}

std::vector<int> mergeSort(std::vector<int> arr) {
}

std::vector<int> quickSort(std::vector<int> arr) {
}
