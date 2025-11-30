// 1. Develop a menu driven program for the following operations of on a Circular as well
// as a Doubly Linked List.
// (a) Insertion anywhere in the linked list (As a first node, as a last node, and
// after/before a specific node).
// (b) Deletion of a specific node, say 'Delete Node 60'. That mean the node to be
// deleted may appear as a head node, last node or a node in between.
// (c) Search for a node.

//a
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *prev, *next;
};

Node* head = NULL;

void insertBegin(int val){
    Node* temp = new Node{val, NULL, NULL};
    if(head == NULL){
        head = temp;
        return;
    }
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertEnd(int val){
    Node* temp = new Node{val, NULL, NULL};
    if(head == NULL){
        head = temp;
        return;
    }
    Node* cur = head;
    while(cur->next) cur = cur->next;
    cur->next = temp;
    temp->prev = cur;
}

void insertAfter(int key, int val){
    Node* cur = head;
    while(cur && cur->data != key) cur = cur->next;
    if(!cur){ cout<<"Key not found\n"; return; }

    Node* temp = new Node{val, cur, cur->next};
    if(cur->next) cur->next->prev = temp;
    cur->next = temp;
}

void deleteNode(int key){
    Node* cur = head;
    while(cur && cur->data != key) cur = cur->next;
    if(!cur){ cout<<"Node not found\n"; return; }

    if(cur->prev) cur->prev->next = cur->next;
    else head = cur->next;

    if(cur->next) cur->next->prev = cur->prev;

    delete cur;
    cout<<"Node deleted\n";
}

void searchNode(int key){
    Node* cur = head;
    while(cur){
        if(cur->data == key){
            cout<<"Node Found\n";
            return;
        }
        cur = cur->next;
    }
    cout<<"Not Found\n";
}

void display(){
    Node* cur = head;
    while(cur){
        cout<<cur->data<<" ";
        cur = cur->next;
    }
    cout<<endl;
}

int main(){
    int ch, x, key;
    while(true){
        cout<<"\n1.Insert Begin\n2.Insert End\n3.Insert After\n4.Delete\n5.Search\n6.Display\n7.Exit\n";
        cin>>ch;
        if(ch==1){ cin>>x; insertBegin(x); }
        else if(ch==2){ cin>>x; insertEnd(x); }
        else if(ch==3){ cin>>key>>x; insertAfter(key,x); }
        else if(ch==4){ cin>>key; deleteNode(key); }
        else if(ch==5){ cin>>key; searchNode(key); }
        else if(ch==6){ display(); }
        else break;
    }
}

