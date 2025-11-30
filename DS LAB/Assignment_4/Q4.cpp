// Q(4) Write a program to find first non-repeating character in a string using Queue : Sample I/P: a a b c Sample O/P: a -1 b b

#include <iostream>
using namespace std;

class Queue {
  char* arr;
  int front, rear, size, capacity;

 public:
  Queue(int cap) {
    capacity = cap;
    arr = new char[capacity];
    front = rear = -1;
    size = 0;
  }

  bool isEmpty() {
    return size == 0;
  }

  void enqueue(char val) {
    if (size == capacity)
      return;
    if (front == -1)
      front = 0;
    rear = (rear + 1) % capacity;
    arr[rear] = val;
    size++;
  }

  char dequeue() {
    if (isEmpty())
      return '\0';
    char val = arr[front];
    if (front == rear)
      front = rear = -1;
    else
      front = (front + 1) % capacity;
    size--;
    return val;
  }

  char peek() {
    if (isEmpty())
      return '\0';
    return arr[front];
  }
};

void firstNonRepeating(string stream) {
  int freq[256] = {0};
  Queue q(stream.length());

  for (char ch : stream) {
    freq[ch]++;
    q.enqueue(ch);

    while (!q.isEmpty() && freq[q.peek()] > 1) {
      q.dequeue();
    }

    if (!q.isEmpty())
      cout << q.peek() << " ";
    else
      cout << "-1 ";
  }
  cout << endl;
}

int main() {
  string stream = "aabc";
  cout << "Input: " << stream << endl;
  cout << "Output: ";
  firstNonRepeating(stream);
  return 0;
}