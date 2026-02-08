#include <iostream>

using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int D[n + 5];
    for (int i = 0; i < n; i++){
        if (i == 0){
            D[i] = a[i];
        }
        else{
            D[i] = a[i] - a[i - 1];
        }
    }

    while(q--){
        int l, r, k;
        cin >> l >> r >> k;
        D[l] += k;
        D[r + 1] -= k;
    }

    for (int i = 0; i < n; i++){
        if (i == 0){
            a[i] = D[i];
        }
        else{
            a[i] = a[i - 1] + D[i];
        }
    }

    for (int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }

    return 0;
}