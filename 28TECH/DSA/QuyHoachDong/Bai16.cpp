#include <iostream>
#define ll long long
#define mod 1000000007

using namespace std;

ll F[1000005];

int main(){
    int n, x;
    cin >> n >> x;

    int a[n + 1];
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    // bai toan con nho nhat
    F[0] = 1;

    for (int i = 1; i <= x; i++){
        F[i] = 0;
        for (int j = 1; j <= n; j++){
            if (i - a[j] >= 0){
                F[i] += F[i - a[j]];
            }
        }
        F[i] %= mod;
    }

    cout << F[x];

    return 0;
}