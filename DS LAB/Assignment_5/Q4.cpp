// Q(4). Write a program to reverse a linked list.
// Input: 1->2->3->4->NULL
// Output: 4->3->2->1->NULL

#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
};

// Insert at end
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

// Function to reverse the linked list
Node* reverseList(Node* head) {
  Node* prev = nullptr;
  Node* curr = head;

  while (curr != nullptr) {
    Node* nextNode = curr->next;  // store next
    curr->next = prev;            // reverse link
    prev = curr;                  // move prev forward
    curr = nextNode;              // move curr forward
  }

  return prev;  // new head
}

void printList(Node* head) {
  while (head != nullptr) {
    cout << head->data << "->";
    head = head->next;
  }
  cout << "NULL";
}

int main() {
  Node* head = nullptr;

  int arr[] = {1, 2, 3, 4};
  int n = 4;

  for (int i = 0; i < n; i++)
    insert(head, arr[i]);

  cout << "Original List: ";
  printList(head);
  cout << endl;

  head = reverseList(head);

  cout << "Reversed List: ";
  printList(head);

  return 0;
}