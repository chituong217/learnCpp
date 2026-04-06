#include <iostream>
#define ll long long

using namespace std;

ll F[1005];

ll solve(int a[], int n){
    for (int i = 0; i < n; i++){
        F[i] = a[i];
    }

    for (int i = 1; i < n; i++){
        for (int j = 0; j < i; j++){
            if (a[i] > a[j]){
                F[i] = max(F[i], a[i] + F[j]);
            }
        }
    }

    ll maxSum = 0;
    for (int i = 0; i < n; i++){
        maxSum = max(maxSum, F[i]);
    }

    return maxSum;
}

int main(){
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    cout << solve(a, n);

    return 0;
}