#include <iostream>

using namespace std;

void heapifyUp(int a[], int left, int right){
    int p = (right - 1)/2;
    if (p < left) return;
    
    if (a[p] < a[right]){
        swap(a[p], a[right]);

        heapifyUp(a, left, p);
    }
}

int main(){
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int k, val;
    cin >> k >> val;

    a[k] = val;
    heapifyUp(a, 0, k);

    for (int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }

    return 0;
}