// Q(1). Write a program to implement following sorting techniques:
// a. Selection Sort
// b. Insertion Sort
// c. Bubble Sort
// d. Merge Sort
// e. Quick Sort

#include <iostream>
using namespace std;

// SELECTION SORT
void selectionSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    int temp = arr[i];
    arr[i] = arr[minIndex];
    arr[minIndex] = temp;
  }
}

// INSERTION SORT
void insertionSort(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

// BUBBLE SORT
void bubbleSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

// MERGE FUNCTION (used by merge sort)
void merge(int arr[], int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  int L[1000], R[1000];

  for (int i = 0; i < n1; i++) {
    L[i] = arr[left + i];
  }
  for (int i = 0; i < n2; i++) {
    R[i] = arr[mid + 1 + i];
  }

  int i = 0, j = 0, k = left;

  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k++] = L[i++];
    } else {
      arr[k++] = R[j++];
    }
  }

  while (i < n1) {
    arr[k++] = L[i++];
  }
  while (j < n2) {
    arr[k++] = R[j++];
  }
}

// MERGE SORT
void mergeSort(int arr[], int left, int right) {
  if (left < right) {
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
}

// PARTITION FUNCTION (used by quick sort)
int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = low - 1;

  for (int j = low; j < high; j++) {
    if (arr[j] < pivot) {
      i++;
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }

  int temp = arr[i + 1];
  arr[i + 1] = arr[high];
  arr[high] = temp;

  return i + 1;
}

// QUICK SORT
void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

// PRINT ARRAY
void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {
  int arr[10] = {64, 25, 12, 22, 11, 90, 34, 2, 99, 17};
  int n = 10;

  cout << "\nOriginal Array: ";
  printArray(arr, n);

  cout << "\n--- Selection Sort ---\n";
  selectionSort(arr, n);

  // cout << "\n--- Insertion Sort ---\n";
  // insertionSort(arr, n);

  // cout << "\n--- Bubble Sort ---\n";
  // bubbleSort(arr, n);

  // cout << "\n--- Merge Sort ---\n";
  // mergeSort(arr, 0, n - 1);

  // cout << "\n--- Quick Sort ---\n";
  // quickSort(arr, 0, n - 1);

  cout << "Sorted Array: ";
  printArray(arr, n);

  return 0;
}