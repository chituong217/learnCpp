#include <iostream>
#include <iomanip>
#include <cmath>
#define MAX_LEN 1000000
#define MOD 1000000007
using namespace std;


int a[MAX_LEN];
long long f[MAX_LEN];

int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    f[0] = a[0];
    for (int i=1; i<n; i++){
        f[i] = f[i-1] + a[i];
    }
    for (int i=0; i<n; i++){
        cout << f[i] << ' ';
    }
    return 0;
}