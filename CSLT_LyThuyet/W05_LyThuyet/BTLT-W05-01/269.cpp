#include <iostream>
#include <cmath>
using namespace std;

void insert(int a[], int &n, int x, int pos){
    for (int i = n - 1; i >= pos; i--){
        a[i+1] = a[i];
    }
    a[pos] = x;
    n++;
}

int main(){
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    int pos = 0;
    for (int i = n-1; i>=0; i--){
        if (x >= a[i]){
            pos = i+1;
            break;
        }
    }
    insert(a, n, x, pos);
    for (int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    return 0;
}