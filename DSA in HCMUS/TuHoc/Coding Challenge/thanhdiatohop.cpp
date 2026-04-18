#include <iostream>
#include <vector>
#define MOD 1000000007
#define P 500000003

using namespace std;

long long f[500005], inv[500005];

long long binPow(long long a, long long b, long long mod) {
    long long res = 1;
    a %= mod;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}

void prep(int n) {
    f[0] = 1;

    for (int i = 1; i <= n; i++) {
        f[i] = (f[i - 1] * i) % P;
    }

    inv[n] = binPow(f[n], P - 2, P);

    for (int i = n - 1; i >= 0; i--) {
        inv[i] = (inv[i + 1] * (i + 1)) % P;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, x;
    cin >> n >> x;
    
    prep(n);

    long long s = 0;
    for (int j = 0; j <= n; j++) {
        long long v2 = f[n] * inv[j] % P * inv[n - j] % P;
        
        int v1 = 0;
        if ((n & j) == j){
            v1 = 1;
        }

        long long k;
        if (v2 % 2 == v1){
            k = v2;
        } 
        else{
            k = v2 + P;
        }

        s = (s + binPow(x, k, MOD)) % MOD;
        
        cout << s;
        if (j != n) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}