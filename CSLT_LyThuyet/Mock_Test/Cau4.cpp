#include <iostream>
#include <cmath>

using namespace std;

struct Node{
    int data;
    Node* pNext;
};

struct List{
    Node* pHead;
};

void moveOdd2LeftEven2Right(List &L){
    Node* OddHead = NULL;
    Node* OddTail = NULL;
    Node* EvenHead = NULL;
    Node* EvenTail = NULL;

    Node* tmp = L.pHead;
    while (tmp != NULL){
        Node* Next = tmp->pNext;
        tmp->pNext = NULL;

        if (!(tmp->data % 2 == 0)){
            if (OddHead == NULL){
                OddHead = tmp;
                OddTail = tmp;
            }
            else{
                OddTail->pNext = tmp;
                OddTail = tmp;
            }
        }
        else{
            if (EvenHead == NULL){
                EvenHead = tmp;
                EvenTail = tmp;
            }
            else{
                EvenTail->pNext = tmp;
                EvenTail = tmp;
            }
        }
        tmp = Next;
    }
    if (OddHead == NULL){
        L.pHead = EvenHead;
    }
    else{
        L.pHead = OddHead;
        OddTail->pNext = EvenHead;
    }
}

void reduceList(List &L, int K){
    Node* head = L.pHead;
    if (head == NULL){
        return;
    }
    while (head->pNext != NULL){
        int cnt = 1;
        Node* tmp = head;
        int sum = head->data;
        Node* next = NULL;
        while (cnt < K && tmp != NULL){
            tmp = tmp->pNext;
            if (tmp == NULL) break;
            sum -= tmp->data;
            cnt++;
            if (cnt == K){
                next = tmp->pNext;
            }
        }
        sum = abs(sum);
        head->data = sum;
        tmp = head->pNext;
        Node* prev = NULL;
        while (tmp != next){
            prev = tmp;
            tmp = tmp->pNext;
            delete(prev);
        }
        head->pNext = next;
    }
}

int main(){

    return 0;
}
