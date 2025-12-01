#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

struct LinkedList {
    Node* head;
};

struct DNode {
    int data;
    DNode* next;
    DNode* prev;
};

Node* createNode(int x) {
    Node* p = new Node;
    if (p == NULL) return NULL;
    p->data = x;
    p->next = NULL;
    return p;
}


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

bool checkEmpty(LinkedList list) {
    if (list.head == NULL) return true;
    return false;
}

void addHead(LinkedList &list, int x) {
    Node* p = createNode(x);
    if (list.head == NULL) {
        list.head = p;
    } else {
        p->next = list.head;
        list.head = p;
    }
}

Node* find(LinkedList list, int x) {
    Node* temp = list.head;
    while (temp != NULL) {
        if (temp->data == x) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void addAfter(LinkedList &list, int a, int x) {
    Node* q = find(list, a);
    if (q != NULL) {
        Node* p = createNode(x);
        p->next = q->next;
        q->next = p;
    }
}

void removeTail(LinkedList &list) {
    if (list.head == NULL) return;
    if (list.head->next == NULL) {
        delete list.head;
        list.head = NULL;
        return;
    }
    Node* temp = list.head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

void removeHead(LinkedList &list) {
    if (list.head == NULL) return;
    Node* temp = list.head;
    list.head = list.head->next;
    delete temp;
}

void removeX(LinkedList &list, int x) {
    if (list.head == NULL) return;
    if (list.head->data == x) {
        removeHead(list);
        return;
    }
    Node* temp = list.head;
    Node* prev = NULL;
    while (temp != NULL && temp->data != x) {
        prev = temp;
        temp = temp->next;
    }
    if (temp != NULL) {
        prev->next = temp->next;
        delete temp;
    }
}
