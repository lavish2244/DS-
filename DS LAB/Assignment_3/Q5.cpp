// Q(5). Write a program to convert an Infix expression into a Postfix expression.

#include <iostream>
using namespace std;

int precedence(char op) {
  if (op == '^')
    return 3;
  if (op == '*' || op == '/')
    return 2;
  if (op == '+' || op == '-')
    return 1;
  return 0;
}

int main() {
  char infix[100], stack[100], postfix[100];
  int top = -1, k = 0;
  cout << "Enter the infix expression (single-digit operands): ";
  cin >> infix;

  for (int i = 0; infix[i] != '\0'; i++) {
    char ch = infix[i];
    if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
      postfix[k++] = ch;
    } else if (ch == '(') {
      stack[++top] = ch;
    } else if (ch == ')') {
      while (top != -1 && stack[top] != '(') {
        postfix[k++] = stack[top--];
      }
      if (top != -1)
        top--;  // pop '('
    } else {    // operator
      while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
        postfix[k++] = stack[top--];
      }
      stack[++top] = ch;
    }
  }
  while (top != -1) {
    postfix[k++] = stack[top--];
  }
  postfix[k] = '\0';
  cout << "Postfix expression: " << postfix << endl;
  return 0;
}