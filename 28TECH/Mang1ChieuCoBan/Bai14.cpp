#include <iostream>
#include <iomanip>
#include <cmath>
#define MAX_LEN 1000000
#define MOD 1000000007
using namespace std;


int a[MAX_LEN];

int ucln(int a, int b){
    while (b){
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    
    int gcd = a[0];
    for (int i=0; i<n; i++){
        gcd = ucln(gcd, a[i]);
    }
    cout << gcd;

    return 0;
}