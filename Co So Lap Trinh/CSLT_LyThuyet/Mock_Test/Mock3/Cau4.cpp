#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* pNext;
};

struct List{
    Node* pHead;
}

void reverseList(List &L){
    Node* prev = NULL;
    Node* curr = L.pHead;
    while (curr != NULL){
        Node* next = curr->pNext;
        curr->pNext = prev;
        prev = curr;
        curr = next;
    }
    L.pHead = prev;
}

bool isPrime(int n){
    if (n < 2) return false;
    for (int i = 2; i*i <= n; i++){
        if (n % i == 0) return false;
    }
    return true;
}

int sizeList(List L){
    Node* head = L.pHead;
    int cnt = 0;
    while (head != NULL){
        cnt++;
        head = head->pNext;
    }
    return cnt;
}

void eraseList(List &L, int pos){
    int size = sizeList(L);
    if (pos < 1 || pos > size) return;
    if (pos == 1){
        Node* tmp = L.pHead;
        if (tmp == NULL) return;
        else{
            L.pHead = tmp->pNext;
            delete tmp;
        }
    }
    else if (pos == size){
        Node* prev = NULL;
        Node* tmp = L.pHead;
        while (tmp->pNext != NULL){
            prev = tmp;
            tmp = tmp->pNext;
        }
        Node* last = tmp;
        delete last;
        prev->pNext = NULL;
    }
    else{
        Node* tmp = L.pHead;
        for (int i = 1; i < size - 1; i++){
            tmp = tmp->pNext;
        }
        Node* del = tmp->pNext;
        tmp->pNext = del->pNext;
        delete del;
    }
}

void removePrimes(List &L) {
    while (L.pHead != NULL && isPrime(L.pHead->data)) {
        Node* temp = L.pHead; 
        L.pHead = L.pHead->pNext;
        delete temp;
    }

    if (L.pHead == NULL) return;

    Node* curr = L.pHead;
    
    while (curr->pNext != NULL) {
        if (isPrime(curr->pNext->data)) {
            Node* temp = curr->pNext;
            curr->pNext = temp->pNext;
            delete temp;
        } else {
            curr = curr->pNext;
        }
    }
}