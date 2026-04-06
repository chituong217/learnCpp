#include <iostream>

using namespace std;

int F[1000005];

int solve(int a[], int n){
    for (int i = 0; i < n; i++){
        F[i] = a[i];
    }

    for (int i = 2; i < n; i++){
        F[i] = max(F[i - 1], F[i - 2] + a[i]);
    }

    int maxSum = 0;
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