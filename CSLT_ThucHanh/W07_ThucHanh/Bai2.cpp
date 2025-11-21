#include <iostream>
#include <cmath>

using namespace std;

bool isSquare(int n){
    if (n < 0) return false; 
    int k = sqrt(n);
    return k * k == n;
}

bool isPrime(int n){
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0){
            return false;
        }
    }
    return n;
}

int main(){
    int n;
    do{
        cin >> n;
    } while (n < 10);
    int *a = new int[n];
    for (int i = 0; i < n; i++){
        do{
            cin >> a[i];
        } while ( a[i] < -1000 || a[i] > 2000);
    }

    for (int i = 0; i < n; i++){
        if (isSquare(a[i])){
            cout << a[i] << endl;
            break;
        }
    }

    int *Prime = new int[n];
    int idxPrime = 0;
    for (int i = 0; i < n; i++){
        if (isPrime(a[i])){
            Prime[idxPrime] = a[i];
            idxPrime++;
        }
    }
    
    for (int i = 0; i < idxPrime; i++){
        cout << Prime[i] << ' ';
    }
    cout << endl;
    
    delete []a;
    delete []Prime;
    return 0;
}