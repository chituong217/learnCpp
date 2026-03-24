#include <iostream>

using namespace std;

int X[100], n;

void in(){
    for (int i = 1; i <= n; i++){
        cout << X[i];
    }
}

void Try(int i){
    // Gan cac gia tri co the cho bit thu i
    for (int j = 0; j <= 1; j++){
        X[i] = j;
        if (i == n){
            in();
            cout << endl;
        }
        else{
            Try(i + 1);
        }
    }
}

int main(){
    cin >> n;
    Try(1);

    return 0;
}