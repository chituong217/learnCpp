#include <iostream>
#define mod 1000000007

using namespace std;

long long findReverseNumber(long long n){
    long long m = 0;
    while (n > 0){
        m = m * 10 + n % 10;
        n /= 10;
    }

    return m;
}

long long binPow(long long n, long long m){
    if (m == 0){
        return 1;
    }

    long long x = binPow(n, m/2);
    if (m % 2 == 0){
        return ((x % mod) * (x % mod)) % mod;
    }
    else{
        return ((((x % mod) * (x % mod)) % mod) * (n % mod)) % mod; 
    }
}

int main(){
    long long n;
    cin >> n;

    long long m = findReverseNumber(n);

    cout << binPow(n, m);

    return 0;
}