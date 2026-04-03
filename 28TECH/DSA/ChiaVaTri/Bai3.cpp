#include <iostream>
#define mod 1000000007

using namespace std;

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

    cout << binPow(2, n - 1);

    return 0;
}