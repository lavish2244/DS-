// Q(5). Write a program to check if a linked list is Circular Linked List or not .
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertEnd(int val) {
    Node* temp = new Node{val, NULL};

    if (head == NULL) {
        head = temp;
        return;
    }

    Node* cur = head;
    while (cur->next)
        cur = cur->next;

    cur->next = temp;
}

bool isCircular(Node* head) {
    if (!head) return false;

    Node* cur = head->next;

    while (cur != NULL && cur != head)
        cur = cur->next;

    return (cur == head);
}

int main() {
    insertEnd(2);
    insertEnd(4);
    insertEnd(6);
    insertEnd(7);
    insertEnd(5);

    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = head;  

    if (isCircular(head))
        cout << "True";
    else
        cout << "False";

    return 0;
}