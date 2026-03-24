#include <iostream>

using namespace std;

int n;
char a[100];
bool isFinal = false;

void khoitao(){
    for (int i = 1; i <= n; i++){
        a[i] = 'B';
    }
}

void sinh(){
    int i = n;
    while (i >= 1 && a[i] == 'A'){
        a[i] = 'B';
        i--;
    }
    
    if (i == 0){
        isFinal = true;
    }
    else{
        a[i] = 'A';
    }
}

int main(){
    cin >> n;

    khoitao();
    while (isFinal == false){
        for (int i = 1; i <= n; i++){
            cout << a[i];
        }
        cout << endl;
        sinh();
    }

    return 0;
}