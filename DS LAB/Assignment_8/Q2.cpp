// Q(2). Implement following functions for Binary Search Trees
// (a) Search a given item (Recursive & Non-Recursive)
// (b) Maximum element of the BST
// (c) Minimum element of the BST
// (d) In-order successor of a given node the BST
// (e) In-order predecessor of a given node the BST

#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;

  Node(int value) {
    data = value;
    left = NULL;
    right = NULL;
  }
};

Node* insert(Node* root, int value) {
  if (root == NULL) {
    return new Node(value);
  }
  if (value < root->data) {
    root->left = insert(root->left, value);
  } else if (value > root->data) {
    root->right = insert(root->right, value);
  }
  return root;
}

// Search (Recursive)
bool searchRecursive(Node* root, int key) {
  if (root == NULL) {
    return false;
  }
  if (root->data == key) {
    return true;
  }
  if (key < root->data) {
    return searchRecursive(root->left, key);
  } else {
    return searchRecursive(root->right, key);
  }
}

// Search (Non-Recursive)
bool searchNonRecursive(Node* root, int key) {
  while (root != NULL) {
    if (root->data == key) {
      return true;
    }
    if (key < root->data) {
      root = root->left;
    } else {
      root = root->right;
    }
  }
  return false;
}

// Maximum Element
int findMax(Node* root) {
  if (root == NULL) {
    cout << "Tree is empty!\n";
    return -1;
  }
  while (root->right != NULL) {
    root = root->right;
  }
  return root->data;
}

// Minimum Element
int findMin(Node* root) {
  if (root == NULL) {
    cout << "Tree is empty!\n";
    return -1;
  }
  while (root->left != NULL) {
    root = root->left;
  }
  return root->data;
}

int main() {
  Node* root = NULL;

  root = insert(root, 50);
  insert(root, 30);
  insert(root, 70);
  insert(root, 20);
  insert(root, 40);
  insert(root, 60);
  insert(root, 80);

  cout << "\n--- Binary Search Tree Operations ---\n\n";

  int searchKey = 400;
  cout << "Search for " << searchKey << ":\n";
  cout << "Recursive: " << (searchRecursive(root, searchKey) ? "Found" : "Not Found") << "\n";
  cout << "Non-Recursive: " << (searchNonRecursive(root, searchKey) ? "Found" : "Not Found")
       << "\n";

  cout << "\nMaximum element: " << findMax(root) << "\n";

  cout << "\nMinimum element: " << findMin(root) << "\n\n";

  return 0;
}