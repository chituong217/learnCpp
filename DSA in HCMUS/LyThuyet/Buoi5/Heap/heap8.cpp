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

    int a[n + 1];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int x;
    cin >> x;
    a[n] = x;

    heapifyUp(a, 0, n);
    

    for (int i = 0; i < n + 1; i++){
        cout << a[i] << ' ';
    }

    return 0;
}