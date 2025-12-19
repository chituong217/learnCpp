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

// Bai 7
Node* GetNodePointer(List l, int index){
    if (l.pHead == NULL || index < 0){
        return NULL;
    }

    int listIndex = 0;
    Node* tmp = l.pHead;
    
    while (tmp != NULL){
        if (listIndex == index){
            return tmp;
        }

        tmp = tmp->pNext;
        listIndex++;
    }

    return NULL;
}
