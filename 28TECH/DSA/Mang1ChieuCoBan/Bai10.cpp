#include <iostream>

using namespace std;

bool isPrime(int n){
    for(int i = 2; i * i <= n; i++){
        if (n % i == 0){
            return false;
        }
    }

    return n > 1;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int sumLeft = 0;
    int sumRight = 0;
    for (int i = 1; i < n; i++){
        sumRight += a[i];
    }

    for (int i = 0; i < n; i++){
        if (isPrime(sumLeft) == true && isPrime(sumRight) == true){
            cout << i << ' ';
        }
        sumLeft += a[i];
        if (i + 1 < n){
            sumRight -= a[i + 1];
        }
    }

    return 0;
}