#include <iostream>

using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;

    int a[n], b[m];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int j = 0; j < m; j++){
        cin >> b[j];
    }

    int c[m + n];
    int i = 0, j = 0, idx = 0;
    while (i < n && j < m){
        if (a[i] < b[j]){
            c[idx++] = a[i++];
        }
        else{
            c[idx++] = b[j++];
        }
    }
    while (i < n){
        c[idx++] = a[i++];
    }
    while (j < m){
        c[idx++] = b[j++];
    }

    k--;
    cout << c[k];

    return 0;
}