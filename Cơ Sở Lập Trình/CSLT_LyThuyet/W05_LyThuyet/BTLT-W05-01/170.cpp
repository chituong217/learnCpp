#include <iostream>
#include <cmath>
using namespace std;

int snt(int a){
    for (int i=2; i<=sqrt(a); i++){
        if (a%i==0){
            return 0;
        }
    }
    return a>1;
}

int Find(int a[], int n){
    int max = a[0];
    for (int i=0; i<n; i++){
        if (a[i] > max){
            max = a[i];
        }
    }
    for (int i = max + 1; i > max; i++){
        if (snt(i)){
            return i;
        }
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    cout << Find(a, n);
    return 0;
}