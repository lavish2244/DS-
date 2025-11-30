// Q(1) Develop a menu driven program demonstrating the following operations on simple Queues: enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().

#include <iostream>
using namespace std;

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

int isEmpty() {
  return front == -1;
}

int isFull() {
  return rear == MAX - 1 && front == 0;
}

void enqueue(int x) {
  if (isFull()) {
    cout << "Queue Overflow !" << endl;
    return;
  }
  if (isEmpty()) {
    front = 0;
  }
  rear++;
  queue[rear] = x;
}

int dequeue() {
  if (isEmpty()) {
    cout << "Queue Underflow !" << endl;
    return -1;
  } else {
    int dequeuedVal = queue[front];
    if (front == rear) {
      front = rear = -1;
    } else {
      front++;
    }
    return dequeuedVal;
  }
}

int getFront() {
  if (isEmpty()) {
    return -1;
  }
  return queue[front];
}

int getRear() {
  if (isEmpty()) {
    return -1;
  } else {
    return queue[rear];
  }
}

void display() {
  if (isEmpty()) {
    cout << "Queue is empty !" << endl;
    return;
  }
  cout << "Queue elements are: " << endl;
  for (int i = front; i <= rear; i++) {
    cout << queue[i] << " ";
  }
  cout << endl;
}

int main() {
  int choice, val;

  do {
    cout << "\n--- Linear Queue Menu ---" << endl;
    cout << "1. Enqueue\n2. Dequeue\n3. isEmpty\n4. isFull\n5. Get Front\n6. "
            "Get Rear\n7. Display\n8. Exit\n";
    cout << "Enter choice: ";
    cin >> choice;
    cout << endl;

    switch (choice) {
      case 1: {
        cout << "Enter value to enqueue: ";
        cin >> val;
        enqueue(val);
        break;
      }
      case 2: {
        int deqVal = dequeue();
        if (deqVal != -1)
          cout << "Dequeued: " << deqVal << endl;
        break;
      }
      case 3: {
        cout << (isEmpty() ? "Queue is empty" : "Queue is not empty") << endl;
        break;
      }
      case 4: {
        cout << (isFull() ? "Queue is full" : "Queue is not full") << endl;
        break;
      }
      case 5: {
        int frontVal = getFront();
        if (frontVal != -1)
          cout << "Front: " << frontVal << endl;
        else
          cout << "Queue is empty" << endl;
        break;
      }
      case 6: {
        int rearVal = getRear();
        if (rearVal != -1)
          cout << "Rear: " << rearVal << endl;
        else
          cout << "Queue is empty" << endl;
        break;
      }
      case 7: {
        display();
        break;
      }
      case 8: {
        cout << "Exiting..." << endl;
        break;
      }
      default: {
        cout << "Invalid choice !" << endl;
        break;
      }
    }
  } while (choice != 8);

  return 0;
}