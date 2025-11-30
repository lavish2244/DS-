// Q(3). Write a program that checks if an expression has balanced parentheses.

#include <iostream>
using namespace std;

int main() {
  char expr[100];
  cout << "Enter the expression: ";
  cin >> expr;

  char stack[100];
  int top = -1;
  bool balanced = true;

  for (int i = 0; expr[i] != '\0'; i++) {
    char ch = expr[i];
    if (ch == '(' || ch == '{' || ch == '[') {
      stack[++top] = ch;
    } else if (ch == ')' || ch == '}' || ch == ']') {
      if (top == -1) {
        balanced = false;
        break;
      }
      char open = stack[top--];
      if ((ch == ')' && open != '(') || (ch == '}' && open != '{') || (ch == ']' && open != '[')) {
        balanced = false;
        break;
      }
    }
  }

  if (balanced && top == -1)
    cout << "Balanced parentheses." << endl;
  else
    cout << "Unbalanced parentheses." << endl;

  return 0;
}