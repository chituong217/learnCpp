#include <iostream>

using namespace std;

int F[1000];
int solve(int a[], int n){
    for (int i = 0; i < n; i++){
        F[i] = 1;
    }

    for (int i = 1; i < n; i++){
        for (int j = 0; j < i; j++){
            if (a[i] > a[j]){
                if (F[i] <= F[j]){
                    F[i] = F[j] + 1;
                }
            }
        }
    }

    int LIS = 0;
    for (int i = 0; i < n; i++){
        if (F[i] > LIS){
            LIS = F[i];
        }
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

    cout << solve(a, n);

    return 0;
}