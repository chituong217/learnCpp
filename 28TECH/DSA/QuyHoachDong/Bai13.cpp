#include <iostream>

using namespace std;

int L[105], R[105], F[105];

int main(){
    int n;
    cin >> n;

    int a[n + 1];
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++){
        L[i] = a[i];
        for (int j = 1; j < i; j++){
            if (a[j] < a[i]){
                L[i] = max(L[i], L[j] + a[i]);
            }
        }
    }

    for (int i = n; i >= 1; i--){
        R[i] = a[i];
        for (int j = i + 1; j <= n; j++){
            if (a[j] < a[i]){
                R[i] = max(R[i], R[j] + a[i]);
            }
        }
    }

    int maxSum = 0;
    for (int i = 1; i <= n; i++){
        F[i] = L[i] + R[i] - a[i];
        maxSum = max(maxSum, F[i]);
    }

    cout << maxSum;

    return 0;
}