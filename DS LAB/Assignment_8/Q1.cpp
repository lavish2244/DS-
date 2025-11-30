// Q(1). Implement traversal for Binary Trees (Inorder, Preorder, Postorder) using recursion.

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

Node* buildTree() {
  int value;

  cin >> value;

  if (value == -1) {
    return NULL;
  }

  Node* root = new Node(value);

  cout << "Enter left child of " << value << ": ";
  root->left = buildTree();

  cout << "Enter right child of " << value << ": ";
  root->right = buildTree();

  return root;
}

// Pre-order: Root->Left->Right
void preOrder(Node* root) {
  if (root == NULL) {
    return;
  }
  cout << root->data << " ";
  preOrder(root->left);
  preOrder(root->right);
}

// In-order: Left->Root->Right
void inOrder(Node* root) {
  if (root == NULL) {
    return;
  }
  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}

// Post-order: Left->Right->Root
void postOrder(Node* root) {
  if (root == NULL) {
    return;
  }
  postOrder(root->left);
  postOrder(root->right);
  cout << root->data << " ";
}

int main() {
  cout << "\n--- Binary Tree Creation (use -1 for no node) ---\n";
  cout << "\nEnter root value: ";

  Node* root = buildTree();

  cout << "\n--- Binary Tree Traversals ---\n";

  cout << "\nPre-order traversal: ";
  preOrder(root);

  cout << "\nIn-order traversal: ";
  inOrder(root);

  cout << "\nPost-order traversal: ";
  postOrder(root);

  cout << "\n";

  return 0;
}