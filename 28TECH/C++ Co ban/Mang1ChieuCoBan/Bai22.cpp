#include <iostream>
#include <iomanip>
#include <cmath>
#define MAX_LEN 1000000
#define MOD 1000000007
using namespace std;


int a[MAX_LEN];

void erase(int a[], int &n, int k){
    for (int i=k; i<n-1; i++){
        a[i] = a[i+1];
    }
    n--;
}

int main(){
    int n;
    int x;
    cin >> n;
    cin >> x;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    int idx = -1;
    for (int i=0; i<n; i++){
        if (a[i] == x){
            idx = i;
            break;
        }
    }
    if (idx == -1){
        cout << "NOT FOUND";
        return 0;
    }
    erase(a, n, idx);
    for (int i=0; i<n; i++){
        cout << a[i] << ' ';
    }
    return 0;
}