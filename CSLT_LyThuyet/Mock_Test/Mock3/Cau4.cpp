#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* pNext;
};

struct List{
    Node* pHead;
};

void mergeSortedLists(List &L1, List &L2){
    Node* tmp1 = L1.pHead;
    Node* tmp2 = L2.pHead;

    if (tmp1 == NULL){
        L1.pHead = tmp2;
        return;
    }
    if (tmp2 == NULL){
        return;
    }

    while (tmp1 != NULL && tmp2 != NULL){
        if (tmp1->data < tmp2->data){
            tmp1 = tmp1->pNext;
        }
        else{
            Node* next1 = tmp1->pNext;
            Node* next2 = tmp2->pNext;
            tmp1->pNext = tmp2;
            tmp2->pNext = next1;
            
            tmp1 = next1;
            tmp2 = next2;
        }
    }
    while (tmp2 != NULL){
        if (tmp1->data > tmp2->data){
            Node* next1 = tmp1->pNext;
            Node* next2 = tmp2->pNext;
            tmp1->pNext = tmp2;
            tmp2->pNext = next1;

            tmp1 = next1;
            tmp2 = next2;
        }
    }
}

void removeDuplicates(List &L){
    Node* tmp = L.pHead;
    if (tmp == NULL || tmp->pNext == NULL) return;
    while (tmp != NULL){
        Node* next = tmp->pNext;
        if (next == NULL) break;
        if (tmp->data == next->data){
            next = next->pNext;
        }
        else{
            tmp->pNext = next;
        }
    }
}