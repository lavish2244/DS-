// Q(5) Write a program to implement a stack using (a) Two queues and (b) One Queue.

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

  void enqueue(int val) {
    if (size == capacity)
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

  int peek() {
    if (isEmpty())
      return -1;
    return arr[front];
  }

  int getSize() {
    return size;
  }
};

// (a) Stack using TWO Queues
class StackTwoQueues {
  Queue q1, q2;

 public:
  StackTwoQueues(int n) : q1(n), q2(n) {}

  void push(int x) {
    q1.enqueue(x);
  }

  int pop() {
    if (q1.isEmpty())
      return -1;
    while (q1.getSize() > 1) {
      q2.enqueue(q1.dequeue());
    }
    int val = q1.dequeue();
    while (!q2.isEmpty()) {
      q1.enqueue(q2.dequeue());
    }
    return val;
  }

  int top() {
    if (q1.isEmpty())
      return -1;
    int val = pop();
    q1.enqueue(val);
    return val;
  }

  bool isEmpty() {
    return q1.isEmpty();
  }
};

// (b) Stack using ONE Queue
class StackOneQueue {
  Queue q;

 public:
  StackOneQueue(int n) : q(n) {}

  void push(int x) {
    q.enqueue(x);
    int sz = q.getSize();
    for (int i = 0; i < sz - 1; i++) {
      q.enqueue(q.dequeue());
    }
  }

  int pop() {
    return q.dequeue();
  }

  int top() {
    return q.peek();
  }

  bool isEmpty() {
    return q.isEmpty();
  }
};

int main() {
  cout << "Stack using TWO Queues\n";
  StackTwoQueues s1(10);
  s1.push(10);
  s1.push(20);
  s1.push(30);
  cout << "Top: " << s1.top() << endl;
  cout << "Pop: " << s1.pop() << endl;
  cout << "Pop: " << s1.pop() << endl;
  cout << "Empty: " << s1.isEmpty() << endl;

  cout << "\nStack using ONE Queue\n";
  StackOneQueue s2(10);
  s2.push(5);
  s2.push(15);
  s2.push(25);
  cout << "Top: " << s2.top() << endl;
  cout << "Pop: " << s2.pop() << endl;
  cout << "Pop: " << s2.pop() << endl;
  cout << "Empty: " << s2.isEmpty() << endl;

  return 0;
}