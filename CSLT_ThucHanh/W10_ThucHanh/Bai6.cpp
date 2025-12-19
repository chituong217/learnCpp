#include <iostream>

using namespace std;

struct Data{
    int x;
};

struct Node{
    Data info;
    Node* pNext;
};

struct List{
    Node* pHead;
    Node* pTail;
};

struct Stack{
    List l;
};

// Bai 6
Node* GetNodePointer(List l, Data info){
    if (l.pHead == NULL){
        return NULL;
    }

    Node* tmp = l.pHead;
    while(tmp != NULL){
        if (tmp->info.x == info.x){
            return tmp;
        }
        tmp = tmp->pNext;
    }

    return NULL;
}