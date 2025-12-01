#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int x) {
    Node* p = new Node;
    if (p == NULL) return NULL;
    p->data = x;
    p->next = NULL;
    return p;
}

struct LinkedList {
    Node* head;
};

void createList(LinkedList &list) {
    list.head = NULL;
}

void addTail(LinkedList &list, int x) {
    Node* p = createNode(x);
    if (list.head == NULL) {
        list.head = p;
    } else {
        Node* temp = list.head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = p;
    }
}

void printList(LinkedList list) {
    Node* temp = list.head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}