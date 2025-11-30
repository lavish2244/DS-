// Q(4). Write a program to check if a doubly linked list of characters is palindrome or not .
#include <iostream>
using namespace std;

struct Node {
    char data;
    Node *prev, *next;
};

Node* head = NULL;

void insertEnd(char ch) {
    Node* temp = new Node{ch, NULL, NULL};

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


bool isPalindrome() {
    if (!head) return true;

    Node *left = head, *right = head;

    while (right->next)
        right = right->next;

    while (left != right && right->next != left) {
        if (left->data != right->data)
            return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}

int main() {
    insertEnd('R');
    insertEnd('A');
    insertEnd('D');
    insertEnd('A');
    insertEnd('R');

    if (isPalindrome())
        cout << "True";
    else
        cout << "False";

    return 0;
}