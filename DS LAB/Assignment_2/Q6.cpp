
// Q(6) Write a program to implement the following operations on a Sparse Matrix,assuming the matrix is represented using a triplet.
// (a) Transpose of a matrix.
// (b) Addition of two matrices.
// (c) Multiplication of two matrices.

#include <iostream>
using namespace std;

struct Element {
  int row, col, val;
};

// a.
void transpose(Element a[], int n) {
  cout << "\n(a) Transpose:" << endl;
  for (int i = 0; i < n; i++) {
    cout << a[i].col << " " << a[i].row << " " << a[i].val << endl;
  }
}

// b.
void add(Element a[], int n1, Element b[], int n2) {
  cout << "\n(b) Addition Result:" << endl;
  int i = 0, j = 0;
  while ((i < n1) && (j < n2)) {
    if ((a[i].row == b[j].row) && (a[i].col == b[j].col)) {
      cout << a[i].row << " " << a[i].col << " " << a[i].val + b[j].val << endl;
      i++;
      j++;
    } else if ((a[i].row < b[j].row) || ((a[i].row == b[j].row) && (a[i].col < b[j].col))) {
      cout << a[i].row << " " << a[i].col << " " << a[i].val << endl;
      i++;
    } else {
      cout << b[j].row << " " << b[j].col << " " << b[j].val << endl;
      j++;
    }
  }
  while (i < n1) {
    cout << a[i].row << " " << a[i].col << " " << a[i].val << endl;
    i++;
  }
  while (j < n2) {
    cout << b[j].row << " " << b[j].col << " " << b[j].val << endl;
    j++;
  }
}

// c.
void multiply(Element a[], int n1, int rows, int cols) {
  int vec[10];
  for (int i = 0; i < cols; i++) {
    vec[i] = i + 1;
  }

  int res[10] = {0};
  for (int i = 0; i < n1; i++) {
    res[a[i].row] += a[i].val * vec[a[i].col];
  }

  cout << "\n(c) Multiplication with Vector: ";
  for (int i = 0; i < rows; i++) {
    cout << res[i] << " ";
  }
  cout << endl;
}

int main() {
  Element A[] = {{0, 0, 5}, {0, 2, 8}, {1, 1, 3}};
  Element B[] = {{0, 0, 1}, {0, 2, 2}, {1, 1, 4}};
  int n1 = 3, n2 = 3;

  transpose(A, n1);
  add(A, n1, B, n2);
  multiply(A, n1, 2, 3);

  return 0;
}
