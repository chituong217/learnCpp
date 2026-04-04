#include <iostream>

using namespace std;

void heapify(int a[], int left, int right){
    int p = left * 2 + 1;

    if (p > right) return;
    if (p + 1 <= right && a[p] < a[p + 1]){
        p = p + 1;
    }

    if (a[left] < a[p]){
        swap(a[p], a[left]);
    }

    heapify(a, p, right);
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    heapify(a, 0, n - 1);

    for (int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }

    return 0;
}