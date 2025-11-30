// Q(4) Implement the logic to
// a) Reverse the elements of an array
// b) Find the matrix multiplication
// c) Find the Transpose of a Matrix

#include <iostream>
using namespace std;

void reverseArray(int arr[], int n) {
  int temp;
  for (int i = 0; i < n / 2; i++) {
    temp = arr[i];
    arr[n - 1 - i] = temp;
  }

  cout << "Reversed Array: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void multiplyMatrix(int a[2][2], int b[2][2]) {
  int c[2][2] = {0};

  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++)
        c[i][j] += a[i][k] * b[k][j];

  cout << "Matrix Multiplication Result:" << endl;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      cout << c[i][j] << " ";
    }
    cout << endl;
  }
}

void transposeMatrix(int a[2][3]) {
  int t[3][2];

  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 3; j++)
      t[j][i] = a[i][j];

  cout << "Transpose of Matrix:" << endl;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      cout << t[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  int arr[5] = {1, 2, 3, 4, 5};
  reverseArray(arr, 5);

  int a[2][2] = {{1, 2}, {3, 4}};
  int b[2][2] = {{5, 6}, {7, 8}};
  multiplyMatrix(a, b);

  int mat[2][3] = {{1, 2, 3}, {4, 5, 6}};
  transposeMatrix(mat);

  return 0;
}