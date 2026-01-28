#include <iostream>
#include <iomanip>
#include <cmath>
#define MAX_LEN 1000000
#define MOD 1000000007
using namespace std;


int a[MAX_LEN];
int b[MAX_LEN];

int main(){
    int n, k;
    cin >> n >> k;
    k %= n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    int idx = 0;
    for (int i = n-k; i < n; i++){
        b[idx] = a[i];
        idx++;
    }
    for (int i = 0; i < n-k; i++){
        b[idx] = a[i];
        idx++;
    }
    for (int i=0; i<idx; i++){
        cout << b[i] << ' ';
    }
    return 0;
}