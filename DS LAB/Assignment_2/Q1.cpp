// Q(1) Implement the binary search algorithm, regarded as a fast search algorithm
// with run-time complexity of Ο(log n) in comparison to the Linear Search.

#include <iostream>
using namespace std;

int BinarySearch(int arr[], int n, int key) {
  int low = 0, high = n - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] == key)
      return mid;
    else if (arr[mid] < key)
      low = mid + 1;
    else
      high = mid - 1;
  }

  return -1;
}

int BinarySearchRecursive(int arr[], int l, int r, int k) {
  if (l > r) {
    return -1;
  }

  int m = (l + r) / 2;
  if (k == arr[m]) {
    return m;
  } else if (k < arr[m]) {
    BinarySearchRecursive(arr, l, m - 1, k);
  } else {
    BinarySearchRecursive(arr, m + 1, r, k);
  }
}

int main() {
  int l, r, k, n;
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 9, 20};
  l = 0;
  r = sizeof(arr) / sizeof(arr[0]) - 1;
  n = sizeof(arr) / sizeof(arr[0]);
  k = 7;

  int result1 = BinarySearch(arr, n, k);
  int result2 = BinarySearchRecursive(arr, l, r, k);

  if (result1 != -1) {
    cout << "Element found at index (Looping): " << result1;
  } else if (result2 != -1) {
    cout << "Element found at index (Recursive): " << result2;
  } else {
    cout << "Element not found";
  }

  return 0;
}