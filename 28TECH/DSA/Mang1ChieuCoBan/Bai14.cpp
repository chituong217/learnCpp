#include <iostream>

using namespace std;

int gcd(int a, int b){
    while (b){
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int ucln = a[0];
    for (int i = 1; i < n; i++){
        ucln = gcd(ucln, a[i]);
    }

    cout << ucln;
    
    return 0;
}