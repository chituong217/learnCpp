#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

struct List{
    Node* head;
};

Node* findMiddleNode(List l){
    if (l.head == NULL){
        return NULL;
    }
    else if (l.head->next == NULL){
        return l.head;
    }

    Node* slow = l.head;
    Node* fast = l.head->next;

    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}