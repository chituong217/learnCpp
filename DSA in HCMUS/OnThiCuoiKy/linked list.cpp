#include <bits/stdc++.h>

using namespace std;

// list

struct Node {
    int data;
    Node* next;
};


Node* createNode(int val){
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = NULL;

    return newNode;
}

void insertAtHead(Node* &head, int val){
    Node* newNode = createNode(val);

    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node* &head, int val){
    if (head == NULL){
        insertAtHead(head, val);
        return;
    }
    
    Node* tmp = head;
    while (tmp->next != NULL){
        tmp = tmp->next;
    }

    tmp->next = createNode(val);
}

void deleteNode(Node* &head, int val){
    Node dummy;
    dummy.next = NULL;
    Node* tail = &dummy;

    Node* tmp = head;
    while (tmp != NULL){
        if (tmp->data == val){
            Node* del = tmp;
            tmp = tmp->next;
            delete del;
        }
        else{
            tail->next = tmp;
            tail = tail->next;
            tmp = tmp->next;
        }
    }

    tail->next = NULL;
    head = dummy.next;
}

void printList(Node* head){
    Node *tmp = head;
    while (tmp != NULL){
        cout << tmp->data << ' ';
        tmp = tmp->next;
    }
}

void freeList(Node* &head){
    Node* tmp = head;
    while (tmp != NULL){
        Node* del = tmp;
        tmp = tmp->next;
        delete del;
    }

    head = NULL;
}
