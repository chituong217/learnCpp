#include <iostream>
#include <iomanip>
#include <cmath>
#define MAX_LEN 1000000
#define MOD 1000000007
using namespace std;


int a[MAX_LEN];

int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    long long sum = 0, tich = 1;
    for (int i=0; i<n; i++){
        sum += a[i];
        sum %= MOD;
        tich *= a[i];
        tich %= MOD;
    }
    cout << sum << endl;
    cout << tich << endl;
    return 0;
}