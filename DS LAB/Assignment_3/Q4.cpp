// Q(4). Write a program for the evaluation of a Postfix expression.

#include <iostream>
using namespace std;

int main() {
  char expr[100];
  cout << "Enter the postfix expression (single-digit operands, space separated): ";
  cin.getline(expr, 100);

  int stack[100];
  int top = -1;

  for (int i = 0; expr[i] != '\0'; i++) {
    char ch = expr[i];
    if (ch == ' ')
      continue;
    if (ch >= '0' && ch <= '9') {
      stack[++top] = ch - '0';
    } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
      if (top < 1) {
        cout << "Invalid expression." << endl;
        return 1;
      }
      int b = stack[top--];
      int a = stack[top--];
      int res;
      switch (ch) {
        case '+':
          res = a + b;
          break;
        case '-':
          res = a - b;
          break;
        case '*':
          res = a * b;
          break;
        case '/':
          res = a / b;
          break;
      }
      stack[++top] = res;
    }
  }
  if (top == 0)
    cout << "Result: " << stack[top] << endl;
  else
    cout << "Invalid expression." << endl;
  return 0;
}