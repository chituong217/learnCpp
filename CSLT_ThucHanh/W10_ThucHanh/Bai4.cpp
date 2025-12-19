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

// Bai 4
void PrintList(List l){
    if (l.pHead == NULL) return;

    Node* tmp = l.pHead;
    while (tmp != NULL){
        cout << tmp->info.x << ' ';
        tmp = tmp->pNext;
    }
}