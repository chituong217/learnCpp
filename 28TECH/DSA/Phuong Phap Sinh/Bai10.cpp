#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[100];
int n, k;
bool isFinal = false;

void khoitao(){
    for (int i = 1; i <= k; i++){
        a[i] = 1;
    }
}

void sinh(){
    int i = k;
    while (i >= 1 && a[i] == n){
        i--;
    }

    if (i == 0){
        isFinal = true;
    }
    else{
        a[i]++;
        for (int j = i + 1; j <= k; j++){
            a[j] = 1;
        }
    }
}

int main(){
    cin >> n >> k;

    khoitao();
    while (isFinal == false){
        for (int i = 1; i <= k; i++){
            cout << a[i];
        }
        cout << endl;
        sinh();
    }

    return 0;
}