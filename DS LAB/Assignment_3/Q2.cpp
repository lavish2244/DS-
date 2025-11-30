// Q(2). Given a string, reverse it using STACK. For example “DataStructure” should be output as “erutcurtSataD.”

#include <iostream>
using namespace std;

#define MAX 20

char stackArr[MAX];
int top = -1;

int isEmpty() {
  return (top < 0);
}

int isFull() {
  return (top >= MAX - 1);
}

void push(char x) {
  if (isFull()) {
    cout << "Stack Overflow! Cannot push " << x << endl;
  } else {
    stackArr[++top] = x;
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

int main() {
  char val;
  int n;
  int size = (sizeof(stackArr) / sizeof(stackArr[0]));

  cout << "\nEnter how many elements you want to insert: ";
  cin >> n;
  cout << "Enter characters into stack separated by space: ";

  for (int i = 0; i < n; i++) {
    cin >> val;
    push(val);
  }

  cout << "\nOriginal Stack: ";
  for (int k = 0; k < size; k++) {
    cout << stackArr[k];
  }

  cout << "\nReversed Stack with reverse loop: ";
  for (int j = top; j >= 0; j--) {
    cout << stackArr[j];
  }

  cout << "\nReversed Stack with popping: ";
  while (!isEmpty()) {
    cout << stackArr[top];
    pop();
  }

  cout << endl;

  return 0;
}