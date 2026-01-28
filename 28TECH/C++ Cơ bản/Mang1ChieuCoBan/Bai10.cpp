#include <iostream>
#include <iomanip>
#include <cmath>
#define MAX_LEN 1000
using namespace std;

bool isPrime(int n){
    for (int i=2; i <= sqrt(n); i++){
        if (n % i == 0){
            return false;
        }
    }
    return n > 1;
}

int main(){
    int n;
    cin >> n;
    int a[MAX_LEN];
    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    for (int i = 1; i < n-1; i++){
        int sumLeft = 0, sumRight = 0;
        for (int j = 0; j < i; j++){
            sumLeft += a[j];
        }
        for (int j = i + 1; j < n; j++){
            sumRight += a[j];
        }
        if (isPrime(sumLeft) && isPrime(sumRight)){
            cout << i << ' ';
        }
    }
    
    return 0;
}