#include <iostream>
#include <algorithm>

using namespace std;

void selectionSort(int a[], int n){
    for (int i = 0; i < n; i++){
        int min = i;
        for (int j = i + 1; j < n; j++){
            if (a[min] < a[j]){
                min = j;
            }
        }

        int tmp = a[min];
        a[min] = a[i];
        a[i] = tmp;
    }
}

int main(){
    int n, q;
    cin >> n >> q;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int d[n + 5];
    for (int i = 0; i < n + 5; i++){
        d[i] = 0;
    }

    while (q--){
        int l, r;
        cin >> l >> r;
        l--; r--;
        d[l] += 1;
        d[r + 1] -= 1;
    }

    int f[n];
    f[0] = d[0];
    for (int i = 1; i < n; i++){
        f[i] = f[i - 1] + d[i];
    }

    sort(a, a + n, greater<int>());
    sort(f, f + n, greater<int>());

    long long sum = 0;
    for (int i = 0; i < n; i++){
        if (f[i] == 0){
            break;
        }
        sum += a[i] * f[i];
    }

    cout << sum;

    return 0;
}