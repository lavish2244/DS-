// Q(5). Implement Heapsort (Increasing / Decreasing order).

#include <iostream>
using namespace std;

// Function to heapify a subtree rooted at index i
void heapify(int arr[], int n, int i, bool isMaxHeap) {
    int root = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(isMaxHeap) {
        // Max Heap for Increasing Order
        if(left < n && arr[left] > arr[root])
            root = left;
        if(right < n && arr[right] > arr[root])
            root = right;
    } else {
        // Min Heap for Decreasing Order
        if(left < n && arr[left] < arr[root])
            root = left;
        if(right < n && arr[right] < arr[root])
            root = right;
    }

    if(root != i) {
        swap(arr[i], arr[root]);
        heapify(arr, n, root, isMaxHeap);
    }
}

// Heap Sort Function
void heapSort(int arr[], int n, bool increasing) {
    bool isMaxHeap = increasing; // Max heap = ascending, Min heap = descending

    // Build heap
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i, isMaxHeap);

    // One by one extract elements from heap
    for(int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, isMaxHeap);
    }
}

// Print function
void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int choice;
    cout << "\n1. Sort in Increasing Order (Ascending)\n";
    cout << "2. Sort in Decreasing Order (Descending)\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if(choice == 1) {
        heapSort(arr, n, true);
        cout << "Sorted in Increasing Order: ";
        printArray(arr, n);
    }
    else if(choice == 2) {
        heapSort(arr, n, false);
        cout << "Sorted in Decreasing Order: ";
        printArray(arr, n);
    }
    else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
