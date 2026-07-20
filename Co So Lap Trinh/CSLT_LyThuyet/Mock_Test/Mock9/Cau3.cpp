#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

struct List{
    Node* head;
};

void removeDuplicates(List &L){
    if (L.head == NULL){
        return;
    }
    else if (L.head->next == NULL){
        return;
    }

    Node dummy;
    Node* tail = &dummy;

    tail->next = L.head;
    tail = tail->next;
    while (tail != NULL && tail->next != NULL){
        if (tail->data == tail->next->data){
            Node* del = tail->next;
            tail->next = del->next;

            delete del;
        }
        else{
            tail = tail->next;
        }
    }

    L.head = dummy.next;
}