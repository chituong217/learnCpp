#include <iostream>

using namespace std;

int F[1005];

int findLIS(int a[], int n){
    for (int i = 0; i < n; i++){
        F[i] = 1;
    }

    for (int i = 1; i < n; i++){
        for (int j = 0; j < i; j++){
            if (a[j] < a[i]){
                F[i] = max(F[i], F[j] + 1);
            }
        }
    }

    int LIS = 0;
    for (int i = 0; i < n; i++){
        LIS = max(LIS, F[i]);
    }

    return LIS;
}

int main(){
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    cout << n - findLIS(a, n);

    return 0;
}