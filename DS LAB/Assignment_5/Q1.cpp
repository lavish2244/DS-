// Q(1) Develop a menu driven program for the following operations on a Singly Linked List.
// (a) Insertion at the beginning.
// (b) Insertion at the end.
// (c) Insertion in between (before or after a node having a specific value, say 'Insert a new Node 35 before/after the Node 30').
// (d) Deletion from the beginning.
// (e) Deletion from the end.
// (f) Deletion of a specific node, say 'Delete Node 60').
// (g) Search for a node and display its position from head.
// (h) Display all the node values.

#include <iostream>
using namespace std;

class Node {
 public:
  int data;
  Node* next;
  Node(int value) {
    data = value;
    next = nullptr;
  }
};

class LinkedList {
 private:
  Node* head;

 public:
  LinkedList() {
    head = nullptr;
  }

  void insertAtBeginning(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
  }

  void insertAtEnd(int value) {
    Node* newNode = new Node(value);
    if (!head) {
      head = newNode;
      return;
    }
    Node* temp = head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = newNode;
  }

  void insertBefore(int target, int value) {
    if (!head) {
      return;
    }
    if (head->data == target) {
      insertAtBeginning(value);
      return;
    }
    Node* temp = head;
    while (temp->next && temp->next->data != target) {
      temp = temp->next;
    }
    if (temp->next) {
      Node* newNode = new Node(value);
      newNode->next = temp->next;
      temp->next = newNode;
    }
  }

  void insertAfter(int target, int value) {
    Node* temp = head;
    while (temp && temp->data != target) {
      temp = temp->next;
    }
    if (temp) {
      Node* newNode = new Node(value);
      newNode->next = temp->next;
      temp->next = newNode;
    }
  }

  void deleteFromBeginning() {
    if (!head) {
      return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
  }

  void deleteFromEnd() {
    if (!head) {
      return;
    }
    if (!head->next) {
      delete head;
      head = nullptr;
      return;
    }
    Node* temp = head;
    while (temp->next->next) {
      temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
  }

  void deleteNode(int value) {
    if (!head) {
      return;
    }
    if (head->data == value) {
      Node* temp = head;
      head = head->next;
      delete temp;
      return;
    }
    Node* temp = head;
    while (temp->next && temp->next->data != value) {
      temp = temp->next;
    }
    if (temp->next) {
      Node* delNode = temp->next;
      temp->next = delNode->next;
      delete delNode;
    }
  }

  int search(int value) {
    Node* temp = head;
    int pos = 1;
    while (temp) {
      if (temp->data == value) {
        return pos;
      }
      temp = temp->next;
      pos++;
    }
    return -1;
  }

  void display() {
    Node* temp = head;
    while (temp) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }
};

int main() {
  LinkedList list;
  int choice, value, target;
  while (true) {
    cout << "\n--- Singly Linked List Menu ---\n";
    cout << "1. Insert at beginning\n";
    cout << "2. Insert at end\n";
    cout << "3. Insert before a value\n";
    cout << "4. Insert after a value\n";
    cout << "5. Delete from beginning\n";
    cout << "6. Delete from end\n";
    cout << "7. Delete a specific node\n";
    cout << "8. Search for a node\n";
    cout << "9. Display all nodes\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
      case 1: {
        cout << "Enter value: ";
        cin >> value;
        list.insertAtBeginning(value);
        break;
      }
      case 2: {
        cout << "Enter value: ";
        cin >> value;
        list.insertAtEnd(value);
        break;
      }
      case 3: {
        cout << "Enter target value: ";
        cin >> target;
        cout << "Enter value to insert: ";
        cin >> value;
        list.insertBefore(target, value);
        break;
      }
      case 4: {
        cout << "Enter target value: ";
        cin >> target;
        cout << "Enter value to insert: ";
        cin >> value;
        list.insertAfter(target, value);
        break;
      }
      case 5: {
        list.deleteFromBeginning();
        break;
      }
      case 6: {
        list.deleteFromEnd();
        break;
      }
      case 7: {
        cout << "Enter value to delete: ";
        cin >> value;
        list.deleteNode(value);
        break;
      }
      case 8: {
        cout << "Enter value to search: ";
        cin >> value;
        int pos = list.search(value);
        if (pos != -1) {
          cout << "Node found at position " << pos << endl;
        } else {
          cout << "Node not found." << endl;
        }
        break;
      }
      case 9: {
        cout << "Linked List: ";
        list.display();
        break;
      }
      case 0: {
        return 0;
      }
      default: {
        cout << "Invalid choice." << endl;
        break;
      }
    }
  }
}