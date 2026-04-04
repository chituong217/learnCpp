#include <iostream>

using namespace std;

void heapify(int a[], int left, int right){
    int p = 2 * left + 1;
    if (p > right) return;
    if (p + 1 <= right && a[p + 1] < a[p]){
        p = p + 1;
    }

    if (a[left] > a[p]){
        swap(a[left], a[p]);

        heapify(a, p, right);
    }
}

void createMinHeap(int a[], int n){
    for (int i = (n - 2)/2; i >= 0; i--){
        heapify(a, i, n - 1);
    }
}

int main(){
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    createMinHeap(a, n);
    cout << a[0] << endl;
    a[0] = a[n - 1];
    n--;
    heapify(a, 0, n - 1);

    for (int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }

    return 0;
}