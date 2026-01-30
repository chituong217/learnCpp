#include <iostream>
#define MOD 1000000007

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    long long tong = 0;
    long long tich = 1;
    for (int i = 0; i < n; i++){
        tong += (a[i] % MOD);
        tong %= MOD;

        tich *= (a[i] % MOD);
        tich %= MOD;
    }

    cout << tong << endl;
    cout << tich << endl;

    return 0;
}