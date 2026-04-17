#include <iostream>


using namespace std;

struct Node{
    int data;
    Node* next;
};

struct Queue{
    Node* front;
    Node* back;
};

Node* createNode(int data){
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void init(Queue &q){
    q.front = q.back = NULL;
}

bool isEmpty(Queue &q){
    return q.front == NULL;
}

void enqueue(Queue &q, int data){
    Node* newNode = createNode(data);

    if (q.front == NULL){
        q.front = q.back = newNode;
    }
    else{
        q.back->next = newNode;
        q.back = q.back->next;
    }
}

int dequeue(Queue &q){
    if (q.front == NULL) return -1;
    
    Node* tmp = q.front;
    q.front = q.front->next;
    if (q.front == NULL){
        q.back = NULL;
    }

    int data = tmp->data;
    delete tmp;
    
    return data;
}

int main(){
    

    return 0;
}