#include <iostream>
#include <cmath>

using namespace std;

#define MAX_LEN 100

bool isPrime(int n){
    for (int i=2; i <= sqrt(n); i++){
        if (n%i == 0){
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

    for (int i=0; i<n; i++){
        if (isPrime(a[i])){
            cout << a[i] << " ";
        }
    }

    return 0;
}