#include <iostream>

using namespace std;

struct Node{
    float data;
    Node* pNext;
};

struct List{
    Node* pHead;
};

void partitionList(List &L, List &L_pass, List &L_fail){
    Node* tmp = L.pHead;

    Node dummyPass;
    Node* tmpPass = &dummyPass;

    Node dummyFail;
    Node* tmpFail = &dummyFail;

    while (tmp != NULL){
        if (tmp->data >= 5){
            tmpPass->pNext = tmp;
            tmp = tmp->pNext;
            tmpPass = tmpPass->pNext;
        }
        else{
            tmpFail->pNext = tmp;
            tmp = tmp->pNext;
            tmpFail = tmpFail->pNext;
        }
    }

    L.pHead = NULL;

    tmpPass->pNext = NULL;
    L_pass.pHead = dummyPass.pNext;

    tmpFail->pNext = NULL;
    L_fail.pHead = dummyFail.pNext;
}