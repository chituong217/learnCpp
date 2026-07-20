#include <iostream>
#include <iomanip>
#include <cmath>
#define MAX_LEN 1000000
#define MOD 1000000007
using namespace std;


int a[MAX_LEN];

bool isReverse(int a[], int n){
    int l = 0, r = n-1;
    while (l <= r){
        if (a[l] != a[r]){
            return false;
        }
        l++; r--;
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    if (isReverse(a, n)){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}