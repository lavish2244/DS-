// Q(3) Write a program interleave the first half of the queue with second half : Sample I/P: 4 7 11 20 5 9 Sample O/P: 4 20 7 5 11 9

#include <iostream>
using namespace std;

class Queue {
  int* arr;
  int front, rear, size, capacity;

 public:
  Queue(int cap) {
    capacity = cap;
    arr = new int[capacity];
    front = rear = -1;
    size = 0;
  }

  bool isEmpty() {
    return size == 0;
  }
  bool isFull() {
    return size == capacity;
  }

  void enqueue(int val) {
    if (isFull())
      return;
    if (front == -1)
      front = 0;
    rear = (rear + 1) % capacity;
    arr[rear] = val;
    size++;
  }

  int dequeue() {
    if (isEmpty())
      return -1;
    int val = arr[front];
    if (front == rear)
      front = rear = -1;
    else
      front = (front + 1) % capacity;
    size--;
    return val;
  }

  int getSize() {
    return size;
  }

  void display() {
    if (isEmpty())
      return;
    int i = front;
    for (int cnt = 0; cnt < size; cnt++) {
      cout << arr[i] << " ";
      i = (i + 1) % capacity;
    }
    cout << endl;
  }
};

void interleaveQueue(Queue& q, int n) {
  if (n % 2 != 0) {
    cout << "Queue must have even number of elements\n";
    return;
  }
  int half = n / 2;
  Queue firstHalf(half);

  for (int i = 0; i < half; i++) {
    firstHalf.enqueue(q.dequeue());
  }

  while (!firstHalf.isEmpty()) {
    q.enqueue(firstHalf.dequeue());
    q.enqueue(q.dequeue());
  }
}

int main() {
  Queue q(10);
  q.enqueue(4);
  q.enqueue(7);
  q.enqueue(11);
  q.enqueue(20);
  q.enqueue(5);
  q.enqueue(9);

  cout << "Original Queue: ";
  q.display();

  interleaveQueue(q, q.getSize());

  cout << "Interleaved Queue: ";
  q.display();
  return 0;
}