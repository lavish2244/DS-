// Q(2). Display all the node values in a circular linked list, repeating value of head node at the end too.
// Input: 20 → 100 → 40 → 80 → 60,
// Output: 20 100 40 80 60 20.
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
        temp->next = head;
        return;
    }

    Node* cur = head;
    while (cur->next != head)
        cur = cur->next;

    cur->next = temp;
    temp->next = head;
}

void displayRepeat() {
    if (!head) return;

    Node* cur = head;
    do {
        cout << cur->data << " ";
        cur = cur->next;
    } while (cur != head);

    cout << head->data;   
}

int main() {
    insertEnd(20);
    insertEnd(100);
    insertEnd(40);
    insertEnd(80);
    insertEnd(60);

    displayRepeat(); 
    return 0;
}