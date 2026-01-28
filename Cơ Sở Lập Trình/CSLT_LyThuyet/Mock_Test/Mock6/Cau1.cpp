#include <iostream>

using namespace std;

bool isPrime(int n){
    if (n < 2) return false;
    for (int i = 2; i*i <= n; i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

bool isSuperPrime(int n){
    while (n > 0){
        if (isPrime(n) == false){
            return false;
        }
        n /= 10;
    }
    return true;
}