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

// Bai 5
Node* CreateNode(Data info){
    Node* newNode = new Node;
    if (newNode == NULL){
        return NULL;
    }

    newNode->info = info;
    newNode->pNext = NULL;

    return newNode;
}