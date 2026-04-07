#include <iostream>
#include <algorithm>

#define ll long long

using namespace std;

ll F[100];

void ktao(int n){
    F[0] = 1;
    F[1] = 1;
    F[2] = 2;
    for (int i = 3; i <= n; i++){
        F[i] = F[i - 1] + F[i - 2] + F[i - 3];
    }
}

int main(){
    int n;
    cin >> n;

    ktao(n);
    cout << F[n];

    return 0;
}