#include <iostream>
#include <iomanip>
#include <cmath>
#define MAX_LEN 1000000
#define MOD 1000000007
using namespace std;


int a[MAX_LEN];

bool isPrime(int n){
    for (int i=2; i <= sqrt(n); i++){
        if (n%i==0){
            return false;
        }
    }
    return n > 1;
}

bool isReverse(int n){
    int res = n, ans = 0;
    while (n){
        ans = ans*10 + n%10;
        n/=10;
    }
    return res == ans;
}

bool isSquare(int n){
    int res = sqrt(n);
    res *= res;
    return res == n;
}

bool isSumPrime(int n){
    int sum = 0;
    while (n){
        sum += n%10;
        n/=10;
    }
    return isPrime(sum);
}

int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    int cntPrime =0, cntReverse = 0, cntSquare = 0, cntSumPrime = 0;
    for (int i=0; i<n; i++){
        if (isPrime(a[i])){
            cntPrime++;
        }
        if (isReverse(a[i])){
            cntReverse++;
        }
        if (isSquare(a[i])){
            cntSquare++;
        }
        if (isSumPrime(a[i])){
            cntSumPrime++;
        }
    }
    cout << cntPrime << endl;
    cout << cntReverse << endl;
    cout << cntSquare << endl;
    cout << cntSumPrime << endl;
    return 0;
}