// Q(5) Space required to store any two-dimensional array is 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ 𝑟𝑜𝑤𝑠 × 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ 𝑐𝑜𝑙𝑢𝑚𝑛𝑠. Assuming an array is used to store elements of the following matrices,implement an efficient way that reduces the space requirement.
// (a) Diagonal Matrix.
// (b) Tri-diagonal Matrix.
// (c) Lower triangular Matrix.
// (d) Upper triangular Matrix.
// (e) Symmetric Matrix

#include <iostream>
using namespace std;

// a.
void diagonalMatrix(int n) {
  int diag[100];
  for (int i = 0; i < n; i++) {
    diag[i] = i + 1;
  }
  cout << "\nDiagonal Matrix stored: ";
  for (int i = 0; i < n; i++) {
    cout << diag[i] << " ";
  }
}

// b.
void tridiagonalMatrix(int n) {
  int size = 3 * n - 2;
  int tri[100];
  for (int i = 0; i < size; i++) {
    tri[i] = i + 1;
  }
  cout << "\nTri-diagonal stored: ";
  for (int i = 0; i < size; i++) {
    cout << tri[i] << " ";
  }
}

// c.
void lowerTriangularMatrix(int n) {
  int size = n * (n + 1) / 2;
  int lower[100];
  int k = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      lower[k++] = (i + 1) * (j + 1);
    }
    cout << "\nLower Triangular stored: ";
    for (int i = 0; i < size; i++) {
      cout << lower[i] << " ";
    }
  }
}

// d.
void upperTriangularMatrix(int n) {
  int size = n * (n + 1) / 2;
  int upper[100];
  int k = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      upper[k++] = (i + 1) * (j + 1);
    }
  }
  cout << "\nUpper Triangular stored: ";
  for (int i = 0; i < size; i++) {
    cout << upper[i] << " ";
  }
}

// e.
void symmetricMatrix(int n) {
  int size = n * (n + 1) / 2;
  int sym[100];
  int k = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      sym[k++] = (i + 1) + (j + 1);
    }
  }
  cout << "\nSymmetric Matrix stored: ";
  for (int i = 0; i < size; i++) {
    cout << sym[i] << " ";
  }
}

int main() {
  int n = 4;

  diagonalMatrix(n);
  tridiagonalMatrix(n);
  lowerTriangularMatrix(n);
  upperTriangularMatrix(n);
  symmetricMatrix(n);

  return 0;
}