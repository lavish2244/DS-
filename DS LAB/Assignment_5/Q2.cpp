// Q(2). Write a program to count the number of occurrences of a given key in a singly linked list and then delete all the occurrences.
// Input: Linked List : 1->2->1->2->1->3->1 , key: 1
// Output: Count: 4 , Updated Linked List: 2->2->3.

#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
};

// Function to insert a node at the end of the list
void insert(Node*& head, int value) {
  Node* newNode = new Node{value, nullptr};

  if (head == nullptr) {
    head = newNode;
    return;
  }

  Node* temp = head;
  while (temp->next != nullptr)
    temp = temp->next;

  temp->next = newNode;
}

// Function to count occurrences of key
int countKey(Node* head, int key) {
  int count = 0;
  while (head != nullptr) {
    if (head->data == key)
      count++;
    head = head->next;
  }
  return count;
}

// Function to delete all occurrences of key
void deleteKey(Node*& head, int key) {
  // Remove occurrences at the head
  while (head != nullptr && head->data == key) {
    Node* temp = head;
    head = head->next;
    delete temp;
  }

  // Remove occurrences beyond the head
  Node* curr = head;
  while (curr != nullptr && curr->next != nullptr) {
    if (curr->next->data == key) {
      Node* temp = curr->next;
      curr->next = curr->next->next;
      delete temp;
    } else {
      curr = curr->next;
    }
  }
}

// Function to print the linked list
void printList(Node* head) {
  while (head != nullptr) {
    cout << head->data;
    if (head->next != nullptr)
      cout << "->";
    head = head->next;
  }
}

int main() {
  Node* head = nullptr;

  int arr[] = {1, 2, 1, 2, 1, 3, 1};
  int n = 7;
  for (int i = 0; i < n; i++)
    insert(head, arr[i]);

  int key = 1;

  int count = countKey(head, key);
  deleteKey(head, key);

  cout << "Count: " << count << endl;
  cout << "Updated Linked List: ";
  printList(head);

  return 0;
}