#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

struct List{
    Node* head;
};  

void appendList(List &l1, List l2){
    if (l1.head == NULL){
        l1.head = l2.head;
    }
    else if (l2.head == NULL){
        return;       
    }
    else{
        Node* tail = l1.head;
        while (tail->next != NULL){
            tail = tail->next;
        }

        tail->next = l2.head;
    }
}