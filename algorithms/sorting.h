#ifndef ALGORITHMS_SORTING_H
#define ALGORITHMS_SORTING_H

#include <vector>

using namespace std;

namespace sorting
{
  vector<int> bubbleSort(vector<int> arr);

  vector<int> selectionSort(vector<int> arr);

  vector<int> insertionSort(vector<int> arr);

  vector<int> mergeSort(vector<int> arr);

  void quickSort(vector<int>& arr, int start, int end);
}

#endif // ALGORITHMS_SORTING_H