// Q1(). Develop a menu driven program demonstrating the following operations on a Stack using array: 
//(i) push(), (ii) pop(), (iii) isEmpty(), (iv) isFull(),(v) display(), and (vi) peek().

#include <iostream>
using namespace std;

#define MAX 100

int stackArr[MAX];
int top = -1;

int isEmpty() {
  return (top < 0);
}

int isFull() {
  return (top >= MAX - 1);
}

void push(int x) {
  if (isFull()) {
    cout << "Stack Overflow! Cannot push " << x << endl;
  } else {
    stackArr[++top] = x;
    cout << x << " pushed into stack." << endl;
  }
}

int pop() {
  if (isEmpty()) {
    cout << "Stack Underflow! Cannot pop." << endl;
    return -1;
  } else {
    return stackArr[top--];
  }
}

int peek() {
  if (isEmpty()) {
    cout << "Stack is empty." << endl;
    return -1;
  } else {
    return stackArr[top];
  }
}

void display() {
  if (isEmpty()) {
    cout << "Stack is empty." << endl;
  } else {
    cout << "Stack Elements Are: " << endl;
    for (int i = top; i >= 0; i--) {
      cout << "Index: " << i << " Element: " << stackArr[i] << "\n";
    }
    cout << endl;
  }
}

int main() {
  int choice, val;

  do {
    cout << "\n--- Stack Menu ---\n";
    cout << "1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. isFull\n6. Display\n7. "
            "Exit\n";
    cout << "\nEnter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1:
        cout << "Enter element to push: ";
        cin >> val;
        push(val);
        break;

      case 2:
        val = pop();
        if (val != -1)
          cout << "Element: " << val << " popped from index: " << top << endl;
        break;

      case 3:
        val = peek();
        if (val != -1)
          cout << "Top element: " << val << endl;
        break;

      case 4:
        cout << (isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;
        break;

      case 5:
        cout << (isFull() ? "Stack is full." : "Stack is not full.") << endl;
        break;

      case 6:
        display();
        break;

      case 7:
        cout << "Exiting program." << endl;
        break;

      default:
        cout << "Invalid choice. Try again." << endl;
    }
  } while (choice != 7);

  return 0;
}