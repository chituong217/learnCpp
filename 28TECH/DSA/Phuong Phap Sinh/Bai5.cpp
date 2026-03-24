#include <iostream>

using namespace std;

int n, k;
int a[100];
bool isFinal = false;

void khoitao(){
    for (int i = 1; i <= k; i++){
        a[i] = i;
    }
}

void sinh(){
    int i = k;
    while (i >= 1 && a[i] == n - k + i){
        i--;
    }

    if (i == 0){
        isFinal = true;
    }
    else{
        a[i]++;
        for (int j = i + 1; j <= k; j++){
            a[j] = a[j - 1] + 1;
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