#include <iostream>
using namespace std;

// stack

struct Node {
    int data;
    Node* next;
};

struct Stack {
    Node* top;
    int capacity;
    int currentSize;
};

void init(Stack& stack, int capacity) {
    stack.top = NULL;
    stack.capacity = capacity;
    stack.currentSize = 0;
}

bool checkEmpty(const Stack &stack) {
    return stack.top == NULL;
}

bool isFull(const Stack &stack) {
    return stack.currentSize >= stack.capacity;
}

void push(Stack &stack, int x) {
    if (isFull(stack)) return;
    
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = stack.top;
    stack.top = newNode;
    stack.currentSize++;
}

int pop(Stack &stack) {
    if (checkEmpty(stack)) return -1;

    Node* temp = stack.top;
    int value = temp->data;
    stack.top = stack.top->next;
    delete temp;
    stack.currentSize--;
    return value;
}

int peek(const Stack &stack) {
    if (checkEmpty(stack)) return -1;
    return stack.top->data;
}


// queue
struct NodeQ {
    int data;
    NodeQ* next;
};

struct Queue {
    NodeQ* head;
    NodeQ* tail;
    int capacity;
    int currentSize;
};

void init(Queue& queue, int capacity) {
    queue.head = NULL;
    queue.tail = NULL;
    queue.capacity = capacity;
    queue.currentSize = 0;
}

bool checkEmpty(const Queue &queue) {
    return queue.head == NULL;
}

bool isFull(const Queue &queue) {
    return queue.currentSize >= queue.capacity;
}

void push(Queue &queue, int x) {
    if (isFull(queue)) return;

    NodeQ* newNode = new NodeQ;
    newNode->data = x;
    newNode->next = NULL;

    if (checkEmpty(queue)) {
        queue.head = queue.tail = newNode;
    } else {
        queue.tail->next = newNode;
        queue.tail = newNode;
    }
    queue.currentSize++;
}

int pop(Queue &queue) {
    if (checkEmpty(queue)) return -1;

    NodeQ* temp = queue.head;
    int value = temp->data;
    queue.head = queue.head->next;

    if (queue.head == NULL) {
        queue.tail = NULL;
    }

    delete temp;
    queue.currentSize--;
    return value;
}

int peek(const Queue &queue) {
    if (checkEmpty(queue)) return -1;
    return queue.head->data;
}