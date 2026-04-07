#include <iostream>
#define ll long long
#define mod 1000000007

using namespace std;

ll F[105][1000005];

int main(){
    int n, x;
    cin >> n >> x;

    int a[n + 1];
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    // bai toan con nho nhat
    for (int i = 0; i <= n; i++){
        F[i][0] = 1;
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= x; j++){
            if (j - a[i] >= 0){
                F[i][j] = F[i][j - a[i]] + F[i - 1][j];
            }
            else{
                F[i][j] = F[i - 1][j];
            }
            F[i][j] %= mod;
        }
    }

    cout << F[n][x];

    return 0;
}