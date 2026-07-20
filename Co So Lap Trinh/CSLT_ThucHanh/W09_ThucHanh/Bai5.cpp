#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

struct Stack{
    Node* top;
    int capacity;
    int currentSize;
};

void init(Stack* stack, int capacity){
    stack->top = NULL;
    stack->capacity = capacity;
    stack->currentSize = 0;
}

bool checkEmpty(Stack *stack) {
    return stack.top == NULL;
}

bool isFull(Stack *stack) {
    return stack.currentSize >= stack.capacity;
}

int pop(Stack* stack){
    if (checkEmpty(stack) == true) return -1;

    int value = stack->top->data;
    Node* del = stack->top;
    stack->top = stack->top->next;
    delete del;
    stack->currentSize--;

    return value;
}

void push(Stack* stack, int value){
    if (isFull(stack) == true) return;

    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = stack->top;
    
    stack->currentSize++;
    stack->top = newNode;
}

void clear(Stack* stack){
    Node* tmp = stack->top;

    for (int i = 0; i < stack->currentSize; i++){
        Node* del = tmp;
        tmp = tmp->next;

        delete del;
    }

    stack->top = NULL;
    stack->currentSize = 0;
}