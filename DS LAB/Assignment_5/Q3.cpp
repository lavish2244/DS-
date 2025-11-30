// Q(3). Write a program to find the middle of a linked list.
// Input: 1->2->3->4->5
// Output: 3

#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
};

// Function to insert nodes at the end
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

// Function to find the middle element
int findMiddle(Node* head) {
  if (head == nullptr)
    return -1;  // or any indication of empty list

  Node* slow = head;
  Node* fast = head;

  // Move fast by 2 steps and slow by 1 step
  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow->data;  // slow will be at middle
}

// Function to print list
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

  int arr[] = {1, 2, 3, 4, 5};
  int n = 5;

  for (int i = 0; i < n; i++)
    insert(head, arr[i]);

  cout << "Linked List: ";
  printList(head);
  cout << endl;

  int middle = findMiddle(head);

  cout << "Middle Element: " << middle << endl;

  return 0;
}