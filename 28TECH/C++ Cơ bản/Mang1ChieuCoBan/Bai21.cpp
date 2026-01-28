#include <iostream>
#include <iomanip>
#include <cmath>
#define MAX_LEN 1000000
#define MOD 1000000007
using namespace std;


int a[MAX_LEN];

void insert(int a[], int &n, int k, int x){
    for (int i= n-1; i >= k; i--){
        a[i+1] = a[i];
    }
    a[k] = x;
    n++;
}


int main(){
    int n;
    int x, k;
    cin >> n;
    cin >> x >> k;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    insert(a, n, k-1, x);
    for (int i=0; i<n; i++){
        cout << a[i] << ' ';
    }
    
    return 0;
}