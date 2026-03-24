#include <iostream>

using namespace std;

// coi 1 la 8 va 0 la 6

int n, a[100];
bool isFinal = false;

void khoitao(){
    for (int i = 1; i <= n; i++){
        a[i] = 0;
    }
}

void sinh(){
    int i = n;
    while (i >= 1 && a[i] == 1){
        a[i] = 0;
        i--;
    }

    if (i == 0){
        isFinal = true;
    }
    else{
        a[i] = 1;
    }
}

bool check(){
    // chu so dau la 1
    if (a[1] != 1){
        return false;
    }
    // chu so cuoi la 0
    if (a[n] != 0){
        return false;
    }
    // khong co 2 chu so 1 canh nhau
    // toi da 3 so 0 canh nhau
    int cnt0 = 0;
    for (int i = 1; i <= n; i++){
        if (a[i] == 1){
            cnt0 = 0;
            if (a[i - 1] == 1){
                return false;
            }
        }
        else{
            cnt0++;
            if (cnt0 > 3){
                return false;
            }
        }
    }

    return true;
}

int main(){
    cin >> n;

    khoitao();
    while (isFinal == false){
        if (check()){
            for (int i = 1; i <= n; i++){
                if (a[i] == 1){
                    cout << '8';
                }
                else{
                    cout << '6';
                }
            }
            cout << endl;
        }
        sinh();
    }

    return 0;
}