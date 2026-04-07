#include <iostream>

using namespace std;

int F[200005];

int main(){
    int n, k;
    cin >> n >> k;

    int a[n + 1];
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    F[0] = 0;
    for (int i = 1; i <= k; i++){
        F[i] = F[i - 1] + a[i];
    }

    for (int i = k + 1; i <= n; i++){
        F[i] = F[i - 1] - a[i - k] + a[i];
    }

    int imin = -1, sumMin = 1e9;
    for (int i = k; i <= n; i++){
        if (F[i] < sumMin){
            sumMin = F[i];
            imin = i - k + 1;
        }
    }

    cout << imin;

    return 0;
}