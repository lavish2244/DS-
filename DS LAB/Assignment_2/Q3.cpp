// Q(3) Design the Logic to Find a Missing Number in a Sorted Array. Given an array of n-1 distinct integers in the range of 1 to n, find the missing number in it in a Sorted Array
// (a) Linear time
// (b) Using binary search

#include <iostream>
using namespace std;

// a.
int findMissingLinear(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    if (arr[i] != i + 1) {
      return i + 1;
    }
  }
  return n + 1;
}

// b.
int findMissingBinary(int arr[], int n) {
  int low = 0, high = n - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] == mid + 1)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return low + 1;
}

int main() {
  int arr[] = {1, 2, 3, 5, 6};
  int n = 5;
  cout << "Missing Number (Linear): " << findMissingLinear(arr, n);
  cout << "Missing Number (Binary): " << findMissingBinary(arr, n);
  return 0;
}