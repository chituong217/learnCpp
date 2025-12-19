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
