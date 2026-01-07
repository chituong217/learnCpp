#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

struct List{
    Node* head;
};

void splitList(List src, List &l1, List &l2){
    Node dummy1;
    Node dummy2;

    Node* tail1 = &dummy1;
    Node* tail2 = &dummy2;

    Node* tmp = src.head;
    while (tmp != NULL){
        if (tmp->data % 2 == 0){
            tail2->next = tmp;
            tail2 = tail2->next;
        }
        else{
            tail1->next = tmp;
            tail1 = tail1->next;
        }
        tmp = tmp->next;
    }
    tail1->next = NULL;
    tail2->next = NULL;

    l1.head = dummy1.next;
    l2.head = dummy2.next;
}