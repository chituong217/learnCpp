#include <iostream>
#include <iomanip>
#include <cmath>
#define MAX_LEN 1000000
#define MOD 1000000007
using namespace std;


int a[MAX_LEN];

void reverseArray(int a[], int n){
    int l = 0, r = n-1;
    while (l <= r){
        int tmp = a[l]; a[l] = a[r]; a[r] = tmp;
        l++; r--;
    }
}


int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    reverseArray(a, n);
    for (int i=0; i<n; i++){
        cout << a[i] << ' ';
    }
    
    return 0;
}