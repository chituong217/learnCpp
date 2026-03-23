#include <bits/stdc++.h>

using namespace std;

int n, a[100], final = 0;

void khoitao(){
    // khoi tao cau hinh dau tien
    for (int i = 1; i <= n; i++){
        a[i] = 0;
    }
}

void sinh(){
    int i = n; // bat dau tu bit cuoi cung

    // tim bit 0 dau tien
    while (i >= 1 && a[i] == 1){
        a[i] = 0;
        i--;
    }

    if (i == 0){
        // cau hinh cuoi cung
        final = 1;
    }
    else{
        // day la bit 0 dau tien tin tu ben phai
        a[i] = 1;
    }
}

int main(){
    cin >> n;

    khoitao();
    while (final == 0){
        for (int i = 1; i <= n; i++){
            cout << a[i];
        }
        cout << endl;
        sinh();
    }

    return 0;
}