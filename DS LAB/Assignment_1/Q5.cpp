// Q (5) Write a program to find sum of every row and every column in a two-dimensional array.

#include <iostream>
using namespace std;

int main() {
  int rows, cols;

  cout << "Enter number of rows: ";
  cin >> rows;
  cout << "Enter number of columns: ";
  cin >> cols;

  int arr[15][15];
  int i, j;

  // Input elements
  cout << "Enter elements of the array:\n";
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      cin >> arr[i][j];
    }
  }

  // Sum (row)
  cout << "\nSum of each row:\n";
  for (i = 0; i < rows; i++) {
    int rowSum = 0;
    for (j = 0; j < cols; j++) {
      rowSum += arr[i][j];
    }
    cout << "Row " << i + 1 << " = " << rowSum << endl;
  }

  // Sum (column)
  cout << "\nSum of each column:\n";
  for (j = 0; j < cols; j++) {
    int colSum = 0;
    for (i = 0; i < rows; i++) {
      colSum += arr[i][j];
    }
    cout << "Column " << j + 1 << " = " << colSum << endl;
  }

  return 0;
}