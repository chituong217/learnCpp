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
    Node* pHead, pTail;
};

struct Stack{
    List l;
};

// Bai 1
int CompareData(Data info1, Data info2){
    if (info1.x < info2.x){
        return -1;
    }
    else if (info1.x == info2.x){
        return 0;
    }
    else{
        return -1;
    }
}

// Bai 2
void InitList(List &l){
    l.pHead = NULL;
    l.pTail = NULL;
}

// Bai 3
bool isEmptyList(List l){
    if (l.pHead == NULL){
        return true;
    }
    return false;
}

// Bai 4
void PrintList(List l){
    if (l.pHead == NULL) return;

    Node* tmp = l.pHead;
    while (tmp != NULL){
        cout << tmp->info.x << ' ';
        tmp = tmp->pNext;
    }
}

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