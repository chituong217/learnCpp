#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

struct List{
    Node* head;
};

void findIntersection(List L1, List L2, List &Result){
    Node dummy;
    Node* tail = &dummy;

    Node* p1 = L1.head;
    Node* p2 = L2.head;

    while (p1 != NULL && p2 != NULL){
        if (p1->data == p2->data){
            if (tail == &dummy || tail->data != p1->data){
                Node* tmp = new Node;
                tmp->data = p1->data;
                tmp->next = NULL;

                tail->next = tmp;
                tail = tmp;
            }

            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->data < p2->data){
            p1 = p1->next;
        }
        else{
            p2 = p2->next;
        }
    }

    Result.head = dummy.next;
}
