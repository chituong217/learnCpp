#include <iostream>
#define mod 1000000007

using namespace std;

long long binPow(long long a, long long b){
    if (b == 0){
        return 1;
    }

    long long X = binPow(a, b/2);
    if (b % 2 == 0){
        return ((X % mod) * (X % mod)) % mod;
    }
    else{
        return ((((X % mod) * (X % mod)) % mod) * (a % mod)) % mod;
    }
}

int main(){
    long long n, k;
    cin >> n >> k;

    cout << binPow(n, k);

    return 0;
}