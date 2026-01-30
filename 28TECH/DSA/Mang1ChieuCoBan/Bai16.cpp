#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n){
    for (int i = 2; i*i <= n; i++){
        if (n % i == 0){
            return false;
        }
    }

    return n > 1;
}

bool isThuanNghich(int n){
    int tmp = n;
    int rev = 0;
    while (tmp){
        rev = rev * 10 + tmp % 10;
        tmp /= 10;
    }
    
    return n == rev;
}

bool isSquare(int n){
    return (int)sqrt(n) == sqrt(n);
}

bool isSumPrime(int n){
    int sum = 0;
    while (n){
        sum += n % 10;
        n /= 10;
    }

    return isPrime(sum);
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int cntPrime = 0, cntSquare = 0, cntThuanNghich = 0, cntSumPrime = 0;
    for (int i = 0; i < n; i++){
        if (isPrime(a[i]) == true){
            cntPrime++;
        }
        if (isThuanNghich(a[i])){
            cntThuanNghich++;
        }
        if(isSquare(a[i])){
            cntSquare++;
        }
        if(isSumPrime(a[i])){
            cntSumPrime++;
        }
    }

    cout << cntPrime << endl;
    cout << cntThuanNghich << endl;
    cout << cntSquare << endl;
    cout << cntSumPrime << endl;

    return 0;
}