#include <bits/stdc++.h>

using namespace std;


// priority queue, min heap

struct MinHeap {
    int* arr;
    int size;
    int capacity;
};

void initHeap(MinHeap &h, int cap){
    h.arr = new int[cap];
    h.size = 0;
    h.capacity = cap;
}

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

void heapifyUp(MinHeap &h, int index){
    while (index > 0){
        int chaIndex = (index - 1)/2;
        if (h.arr[index] < h.arr[chaIndex]){
            swap(h.arr[index], h.arr[chaIndex]);
            index = chaIndex;
        }
        else{
            break;
        }
    }
}

void heapifyDown(MinHeap &h, int index){
    int p = index*2 + 1;
    if (p >= h.size) return;

    if (p + 1 < h.size && h.arr[p + 1] < h.arr[p]){
        p++;
    }
    
    if (h.arr[index] > h.arr[p]){
        swap(h.arr[index], h.arr[p]);
        heapifyDown(h, p);
    }
}

void push(MinHeap &h, int val){
    if (h.size == h.capacity) return;

    h.arr[h.size] = val;
    h.size++;

    heapifyUp(h, h.size - 1);
}

void pop(MinHeap &h){
    if (h.size == 0) return;

    int n = h.size;
    h.arr[0] = h.arr[n - 1];
    h.size--;

    heapifyDown(h, 0);
}

int getMin(const MinHeap &h){
    if (h.size == 0) return -1;
    return h.arr[0];
}

void buildHeap(MinHeap &h, int* inputArr, int n){
    for (int i = 0; i < n && i < h.capacity; i++){
        h.arr[i] = inputArr[i];
    }

    for (int i = (h.size - 1) / 2; i >= 0; i--){
        heapifyDown(h, i);
    }
}

void freeHeap(MinHeap &h){
    delete[] h.arr;
    h.size = 0;
    h.capacity = 0;
}

