// Q(6). Implement priority queues using heaps.

#include <iostream>
using namespace std;

#define MAX 100

class PriorityQueue {
private:
    int heap[MAX];
    int size;

    // Heapify upwards after insertion
    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        if(index > 0 && heap[parent] < heap[index]) {
            swap(heap[parent], heap[index]);
            heapifyUp(parent);
        }
    }

    // Heapify downwards after deletion
    void heapifyDown(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if(left < size && heap[left] > heap[largest])
            largest = left;
        if(right < size && heap[right] > heap[largest])
            largest = right;

        if(largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    PriorityQueue() {
        size = 0;
    }

    // Insert element into priority queue
    void insert(int value) {
        if(size == MAX) {
            cout << "Priority Queue is Full!" << endl;
            return;
        }
        heap[size] = value;
        size++;
        heapifyUp(size - 1);
    }

    // Delete highest priority (max element)
    void deleteMax() {
        if(size == 0) {
            cout << "Priority Queue is Empty!" << endl;
            return;
        }
        cout << "Deleted element: " << heap[0] << endl;
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
    }

    // Display elements
    void display() {
        if(size == 0) {
            cout << "Priority Queue is Empty!" << endl;
            return;
        }
        cout << "Priority Queue Elements: ";
        for(int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    int choice, value;

    do {
        cout << "\n--- Priority Queue Menu ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete Max\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                pq.insert(value);
                break;

            case 2:
                pq.deleteMax();
                break;

            case 3:
                pq.display();
                break;

            case 4:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid option!" << endl;
        }
    } while(choice != 4);

    return 0;
}
