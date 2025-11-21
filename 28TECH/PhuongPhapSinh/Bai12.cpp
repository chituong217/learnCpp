#include <iostream>
#include <cstring>

using namespace std;

int n, k, a[100];
bool final;

void ktao(){
    for (int i = 1; i <= n; i++){
        a[i] = 0;
    }
}

void sinh(){
    int i = n; 
    while (i > 0 && a[i] == 1){
        a[i] = 0;
        i--;
    }
    if (i == 0){
        final = true;
    }
    a[i] = 1;
}

bool dembit1(){
    int cnt = 0;
    for (int i=1; i<=n; i++){
        if (a[i] == 1){
            cnt++;
        }
    }
    return cnt == k;
}

bool kbit1lientiep(){
    int cnt = 0;
    int cntOnly = 0;
    for (int i=1; i<=n; i++){
        while (a[i] == 1 && i <= n){
            ++cnt;
            i++;
        }
        if (k == cnt){
            cntOnly++;
        }
        cnt = 0;
    }
    return cntOnly == 1;
}

int main(){
    cin >> n >> k;
    final = false;
    ktao();
    while (final == false){
        if (dembit1()){
            for (int i = 1; i <= n; i++){
                cout << a[i];
            }
            cout << " ";
        }
        sinh();
    }
    cout << endl;
    final = false;
    while (final == false){
        if (kbit1lientiep()){
            for (int i = 1; i <= n; i++){
                cout << a[i];
            }
            cout << " ";
        }
        sinh();
    }
    return 0;
}