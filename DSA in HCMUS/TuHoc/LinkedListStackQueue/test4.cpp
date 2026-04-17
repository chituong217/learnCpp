#include <iostream>
#define MAX 100

using namespace std;

struct PriorityQueue{
    int node[100];
    int size;
};

void init(PriorityQueue &pq){
    pq.size = 0;
}

void heapify(int a[], int left, int right){
    int p = 2 * left + 1;
    if (p > right) return;
    if (p + 1 <= right && a[p] < a[p + 1]){
        p = p + 1;
    }

    if (a[left] < a[p]){
        swap(a[left], a[p]);

        heapify(a, p, right);
    }
}

void createHeap(int a[], int n){
    for (int i = (n - 1)/2; i >= 0; i--){
        heapify(a, i, n - 1);
    }
}

int main(){

    return 0;
}