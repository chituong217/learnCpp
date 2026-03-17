#include <iostream>
#include <string>
#define MOD 1000000007

using namespace std;

long long moduleBy(string n, long long m){
    long long res = 0;

    for (int i = 0; i < (int)n.size(); i++){
        res = ((__int128_t)res * 10 + (n[i] - '0')) % m;
    }

    return res;
}

long long binPow(string n, long long b){
    long long a = moduleBy(n, MOD);
    long long res = 1;
    
    while (b){
        if (b % 2 == 1){
            res = ((res % MOD) * (a % MOD)) % MOD; 
        }
        a *= a;
        a %= MOD;
        b /= 2;
    }

    return res % MOD;
}

int main(){
    string n;
    cin >> n;

    long long m;
    cin >> m;

    cout << binPow(n, m);

    return 0;
}