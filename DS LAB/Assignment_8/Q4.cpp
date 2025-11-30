// Q(4). Write a program to determine whether a given binary tree is a BST or not.

#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Create new node
Node* newNode(int value) {
    Node* temp = new Node();
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert for normal binary tree (not BST insert)
Node* insertManual() {
    Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(20);
    root->left->left = newNode(3);
    root->left->right = newNode(7);
    root->right->left = newNode(15);
    return root;
}


// Helper function
bool isBSTUtil(Node* root, int minVal, int maxVal) {
    if(root == NULL)
        return true;

    if(root->data <= minVal || root->data >= maxVal)
        return false;

    return ( isBSTUtil(root->left, minVal, root->data) &&
             isBSTUtil(root->right, root->data, maxVal) );
}

// Main BST check function
bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    Node* root = insertManual(); // Static binary tree for demonstration

    if(isBST(root))
        cout << "It is a Binary Search Tree" << endl;
    else
        cout << "It is NOT a Binary Search Tree" << endl;

    return 0;
}
