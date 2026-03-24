#include <bits/stdc++.h>

using namespace std;

void sinh(int a[], int n){
    int i = n - 1;
    while (i >= 1 && a[i] > a[i + 1]){
        i--;
    }

    if (i == 0){
        for (int j = 1; j <= n; j++){
            a[j] = j;
        }
    }
    else{
        int j = n;
        while (a[i] > a[j]){
            j--;
        }
        swap(a[i], a[j]);
        reverse(a + i + 1, a + n + 1);
    }
}

int main(){
    int n;
    cin >> n;

    int a[n + 1];
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    sinh(a, n);

    for (int i = 1; i <= n; i++){
        cout << a[i] << ' ';
    }

    return 0;
}