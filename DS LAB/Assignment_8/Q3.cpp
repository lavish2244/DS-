// Q(3). Write a program for binary search tree (BST) having functions for the following operations:
// (a) Insert an element (no duplicates are allowed),
// (b) Delete an existing element,
// (c) Maximum depth of BST
// (d) Minimum depth of BST

#include <iostream>
#include <algorithm> // for max and min
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert function
Node* insertNode(Node* root, int value) {
    if(root == NULL) {
        return createNode(value);
    }

    if(value < root->data)
        root->left = insertNode(root->left, value);
    else if(value > root->data)
        root->right = insertNode(root->right, value);
    else
        cout << "Duplicate values not allowed!" << endl;

    return root;
}

// Find minimum node (helper for delete)
Node* findMin(Node* root) {
    while(root && root->left != NULL)
        root = root->left;
    return root;
}

// Delete function
Node* deleteNode(Node* root, int value) {
    if(root == NULL) {
        cout << "Value not found!" << endl;
        return root;
    }

    if(value < root->data)
        root->left = deleteNode(root->left, value);
    else if(value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        // Case 1 : No child
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // Case 2 : One child
        else if(root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3 : Two children
        else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

// Maximum depth function
int maxDepth(Node* root) {
    if(root == NULL) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// Minimum depth function
int minDepth(Node* root) {
    if(root == NULL) return 0;
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

// Display (Inorder Traversal)
void inorder(Node* root) {
    if(root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Main function with menu
int main() {
    Node* root = NULL;
    int choice, value;

    do {
        cout << "\n---- BST Operations ----\n";
        cout << "1. Insert Element\n";
        cout << "2. Delete Element\n";
        cout << "3. Display BST (Inorder)\n";
        cout << "4. Maximum Depth of BST\n";
        cout << "5. Minimum Depth of BST\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insertNode(root, value);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                root = deleteNode(root, value);
                break;
            case 3:
                cout << "BST (Inorder Traversal): ";
                inorder(root);
                cout << endl;
                break;
            case 4:
                cout << "Maximum Depth: " << maxDepth(root) << endl;
                break;
            case 5:
                cout << "Minimum Depth: " << minDepth(root) << endl;
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while(choice != 6);

    return 0;
}
