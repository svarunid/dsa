#include "sorting.h"
#include <vector>

using namespace std;
using namespace sorting;

// A naive sorting algorithm with a time complexity of O(n^2). 
// Sorts array in place and is stable.
vector<int> bubbleSort(vector<int> arr) {
  int n = arr.size();
  for (int i = n - 1; i >= 0; i--){
    bool swapped = false;
    for (int j = 0; j < i; j++){
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        swapped = true;
      }
    }
    if (!swapped) return arr;
  }
  return arr;
}

// Finds minimum element and places it at the beginning of the array.
// Time complexity of O(n^2), in place, and stable.
vector<int> selectionSort(vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    int min = i;
    for (int j = i + 1; j < arr.size(); j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }
    swap(arr[i], arr[min]);
  }
  return arr;
}

// Repeatedly inserts an element into the sorted portion of the array.
// Time complexity of O(n^2), in place, and stable.
vector<int> insertionSort(vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    int current = i;
    while (current > 0 && arr[current] < arr[current - 1]) {
      swap(arr[current], arr[current - 1]);
      current--;
    }
  }
}

// Split the array into smaller arrays, sort them, and merge them back together.
// Time complexity of O(nlogn), not in place, and stable.
vector<int> mergeSort(vector<int> arr) {
  int n = arr.size();
  if (n < 2) return arr;

  int mid = n / 2;
  vector<int> left_arr = sorting::mergeSort(vector<int>(arr.begin(), arr.begin() + mid));
  vector<int> right_arr = sorting::mergeSort(vector<int>(arr.begin() + mid, arr.end()));

  vector<int> result;
  int left = 0, right = 0;

  while (left < mid || right < n - mid) {
    if (left == mid) {
      result.push_back(right_arr[right++]);
      right++;
    } else if (right == n - mid) {
      result.push_back(left_arr[left]);
      left++;
    } else if (left_arr[left] <= right_arr[right]) {
      result.push_back(left_arr[left++]);
      left++;
    } else {
      result.push_back(right_arr[right++]);
      right++;
    }
  }

  return result;
}

// Pick a pivot, partition the array, and recursively sort the sub-arrays.
// Time complexity of O(nlogn), unstable and in-place.
void quickSort(vector<int>& arr, int start, int end) {
  if (start >= end) return;

  int pivot = arr[start + (end - start) / 2];
  int left_ptr = start;
  int right_ptr = end;

  while (left_ptr <= right_ptr) {
    while (arr[left_ptr] < pivot) left_ptr++;
    while (arr[right_ptr] > pivot) right_ptr--;

    if (left_ptr <= right_ptr) {
      swap(arr[left_ptr], arr[right_ptr]);
      left_ptr++;
      right_ptr--;
    }
  }

  sorting::quickSort(arr, start, right_ptr);
  sorting::quickSort(arr, left_ptr, end);
}