#include <iostream>
#include <algorithm>

using namespace std;

int n, cnt;
int a[100];
bool isFinal = false;

void khoitao(){
    cnt = 1;
    a[1] = n;
}

void sinh(){
    // bat dau tu so hang cuoi cung va tim so hang dau tien != 1
    int i = cnt;
    while (i >= 1 && a[i] == 1){
        i--;
    }

    if (i == 0){
        isFinal = true;
    }
    else{
        a[i]--;
        int d = cnt - i + 1; // so luong don vi thieu, so luong so 1 da bo qua va 1 don vi a[i] giam
        
        cnt = i;
        int q = d / a[i]; // tinh d gap may lan a[i]
        int r = d % a[i]; // phan du
        for (int j = 1; j <= q; j++){
            a[i + j] = a[i];
            cnt++;
        }
        if (r != 0){
            cnt++;
            a[cnt] = r;
        }
    }
}

int main(){
    cin >> n;

    khoitao();
    while (isFinal == false){
        for (int i = 1; i <= cnt; i++){
            cout << a[i] << ' ';
        }
        cout << endl;
        sinh();
    }

    return 0;
}