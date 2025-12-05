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
    if (L1.pHead == NULL){
        L1.pHead = L2.pHead;
        return;
    } 
    if (L2.pHead == NULL){
        return;
    }

    Node* tmp1 = L1.pHead;
    Node* tmp2 = L2.pHead;

    Node dummy;
    Node* tail = &dummy;

    while (tmp1 != NULL && tmp2 != NULL){
        if (tmp1->data < tmp2->data){
            tail->pNext = tmp1;
            tail = tmp1;
            tmp1 = tmp1->pNext;
        }
        else{
            tail->pNext = tmp2;
            tail = tmp2;
            tmp2 = tmp2->pNext;
        }
    }
    
    if (tmp1 == NULL){
        tail->pNext = tmp2;
    }
    else{
        tail->pNext = tmp1;
    }

    L1.pHead = dummy.pNext;
    L2.pHead = NULL;
}

void removeDuplicates(List &L){
    Node* tmp = L.pHead;
    if (tmp == NULL) return;

    while (tmp != NULL && tmp->pNext != NULL){
        if (tmp->data == tmp->pNext->data){
            Node* duplicate = tmp->pNext;
            tmp->pNext = duplicate->pNext;
            delete duplicate; 
        }
        else{
            tmp = tmp->pNext;
        }
    }
}