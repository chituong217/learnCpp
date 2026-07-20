#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

struct Queue{
    Node* head;
    Node* tail;
    int capacity;
    int currentSize;
};

void init(Queue* queue, int capacity){
    queue->head = NULL;
    queue->tail = NULL;
    queue->capacity = capacity;
    queue->currentSize = 0;
}

bool checkEmpty(Queue* queue){
    if (queue->head == NULL) return true;
    else return false;
}

bool isFull(Queue* queue){
    if (queue->currentSize >= queue->capacity) return true;
    else return false;
}

int pop(Queue* queue){
    if (checkEmpty(queue) == true) return -1;

    int value = queue->head->data;
    Node* del = queue->head;
    queue->head = queue->head->next;
    if (queue->head == NULL){
        queue->tail = NULL;
    }
    delete del;
    queue->currentSize--;

    return value;
}

void push(Queue* queue, int value){
    if (isFull(queue) == true) return;

    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    if (checkEmpty(queue) == true){
        queue->head = newNode;
        queue->tail = newNode;
    }
    else{
        queue->tail->next = newNode;
        queue->tail = queue->tail->next;
    }

    queue->currentSize++;
}

void clear(Queue* queue){
    if (checkEmpty(queue) == true) return;

    Node* tmp = queue->head;
    for (int i = 0; i < queue->currentSize; i++){
        Node* del = tmp;
        tmp = tmp->next;

        delete del;
    }

    queue->head = queue->tail = NULL;
    queue->currentSize = 0;
}