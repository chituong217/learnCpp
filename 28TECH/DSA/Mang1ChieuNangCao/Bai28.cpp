#include <iostream>
#include <algorithm>
#define MOD 1000000007

using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a, a + n);
    long long sum = 0;
    for (int i = 0; i < n; i++){
        sum += (1ll * a[i] * i) % MOD;
        sum %= MOD;
    }

    cout << sum;

    return 0;
}