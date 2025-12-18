#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* pNext;
};

struct List{
    Node* pHead;
};

void moveMinToHead(List &L){
    if (L.pHead == NULL || L.pHead->pNext == NULL) return;

    int min = L.pHead->data;
    Node* tmp = L.pHead;
    while (tmp != NULL){
        if (tmp->data < min){
            min = tmp->data;
        }
        tmp = tmp->pNext;
    }

    Node* prev = NULL;
    tmp = L.pHead;
    while (tmp != NULL){
        if (tmp->data == min){
            if (prev == NULL){
                break;
            }
            prev->pNext = tmp->pNext;
            tmp->pNext = L.pHead;

            L.pHead = tmp;

            return;
        }
        prev = tmp;
        tmp = tmp->pNext;
    }
}

void compressList(List &L){
    if (L.pHead == NULL || L.pHead->pNext == NULL) return;
    Node* head = L.pHead;

    while (head != NULL){
        Node* tmp = head->pNext;
        int sum = head->data;

        while (tmp != NULL && head->data == tmp->data){
            sum += tmp->data;
            tmp = tmp->pNext;
        }

        Node* need_delete = head->pNext;
        while (need_delete != tmp){
            Node* del = need_delete;
            need_delete = del->pNext;
            delete del;
        }
        
        head->data = sum;
        head->pNext = tmp;
        
        head = tmp;
    }
}