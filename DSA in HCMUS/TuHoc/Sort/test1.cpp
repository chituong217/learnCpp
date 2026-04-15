#include <iostream>

using namespace std;

void heapify(int a[], int left, int right){
    int p = left * 2 + 1;
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

void heapSort(int a[], int n){
    createHeap(a, n);

    for (int i = n - 1; i > 0; i--){
        swap(a[0], a[i]);
        heapify(a, 0, i - 1);
    }
}

int main(){
    int n;
    cin >> n;
    
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    heapSort(a, n);
    for (int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }

    return 0;
}