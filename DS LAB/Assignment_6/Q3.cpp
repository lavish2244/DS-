// Q(3). Write a program to find size of
// i. Doubly Linked List.
// ii. Circular Linked List.

//i.
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev, *next;
};

Node* head = NULL;

void insertEnd(int val) {
    Node* temp = new Node{val, NULL, NULL};
    if (head == NULL) {
        head = temp;
        return;
    }
    Node* cur = head;
    while (cur->next)
        cur = cur->next;

    cur->next = temp;
    temp->prev = cur;
}

int sizeDLL() {
    int count = 0;
    Node* cur = head;
    while (cur) {
        count++;
        cur = cur->next;
    }
    return count;
}

int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);

    cout << "Size of Doubly Linked List = " << sizeDLL();
    return 0;
}

//ii.
// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node* next;
// };

// Node* head = NULL;

// // Insert at end of Circular Linked List
// void insertEnd(int val) {
//     Node* temp = new Node{val, NULL};

//     if (head == NULL) {
//         head = temp;
//         temp->next = head;
//         return;
//     }

//     Node* cur = head;
//     while (cur->next != head)
//         cur = cur->next;

//     cur->next = temp;
//     temp->next = head;
// }

// // Size of CLL
// int sizeCLL() {
//     if (!head) return 0;

//     int count = 0;
//     Node* cur = head;

//     do {
//         count++;
//         cur = cur->next;
//     } while (cur != head);

//     return count;
// }

// int main() {
//     insertEnd(20);
//     insertEnd(100);
//     insertEnd(40);

//     cout << "Size of Circular Linked List = " << sizeCLL();
//     return 0;
// }