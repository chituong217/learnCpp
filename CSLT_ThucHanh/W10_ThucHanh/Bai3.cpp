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

// Bai 3
bool isEmptyList(List l){
    if (l.pHead == NULL){
        return true;
    }
    return false;
}