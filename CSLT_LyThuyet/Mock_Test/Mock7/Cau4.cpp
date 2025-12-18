#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* pNext;
};

struct List{
    Node* pHead;
};

void removeNthFromEnd(List &L, int k){
    int size = 0;
    Node* dem = L.pHead;
    while (dem != NULL){
        dem = dem->pNext;
        size++;
    }

    if (k > size || k  <= 0) return;

    if (k == size){
        if (L.pHead == NULL) return;
        
        Node* tmp = L.pHead;
        L.pHead = L.pHead->pNext;
        delete tmp;
    }
    else if (k == 1){
        if (L.pHead == NULL) return;
        else if (L.pHead->pNext == NULL){
            Node* tmp = L.pHead;
            L.pHead = NULL;
            delete tmp;
        }

        Node* tmp = L.pHead;
        while (tmp->pNext->pNext != NULL){
            tmp = tmp->pNext;
        }
        Node* last = tmp->pNext;
        tmp->pNext = NULL;
        delete last;
    }
    else{
        Node* tmp = L.pHead;
        for (int i = 1; i < size - k; i++){
            tmp = tmp->pNext;
        }
        Node* del = tmp->pNext;
        tmp->pNext = del->pNext;
        delete del;
    }
}