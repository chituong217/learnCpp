#include <iostream>
#include <string>

using namespace std;

long long moduleBy(string n, long long m){
    long long res = 0;

    for (int i = 0; i < (int)n.size(); i++){
        res = ((__int128_t)res * 10 + (n[i] - '0')) % m;
    }

    return res;
}

long long gcd(long long a, long long b){
    while (b){
        long long r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main(){
    string n;
    long long m;

    cin >> n >> m;
    long long mod = moduleBy(n, m);

    long long ucln = gcd(m, mod);
    cout << ucln;

    return 0;
}