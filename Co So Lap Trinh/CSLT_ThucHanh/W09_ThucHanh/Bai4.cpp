#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node{
    int data;
    Node* next;
};

struct List{
    Node* head;
};

void sapxepList(List* list, bool(*compare)(Node* a, Node* b)){
    for (Node* i = list->head; i != NULL; i = i->next){
        Node* min = i;

        for (Node* j = i->next; j != NULL; j = j->next){
            if (compare(min, j) == true){
                min = j;
            }
        }

        int tmp = min->data;
        min->data = i->data;
        i->data = tmp;
    }
}