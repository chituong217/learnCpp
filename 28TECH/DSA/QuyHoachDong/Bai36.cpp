#include <iostream>
#define ll long long
#define mod 1000000007

using namespace std;

ll C[1005][1005];

void ktao(){
    C[0][0] = 1;
    
    for(int i = 1; i <= 1000; i++){
        C[i][0] = 1;
        for (int j = 1; j < i; j++){
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            C[i][j] %= mod;
        }
        C[i][i] = 1;
    }
}

int main(){
    int n;
    cin >> n;

    ktao();
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= i; j++){
            cout << C[i][j] << ' ';
        }
        cout << "\n";
    }

    return 0;
}