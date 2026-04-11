#include <iostream>
#include <algorithm>

using namespace std;

int F[105][105];

int main(){
    int n;
    cin >> n;

    int a[n + 1][n + 1];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++){
        F[0][i] = -1e9;
        F[n + 1][i] = -1e9;
    }

    for (int j = 1; j <= n; j++){
        for (int i = 1; i <= n; i++){
            if (j == 1){
                F[i][j] = a[i][j];
                continue;
            }
            F[i][j] = max({F[i - 1][j - 1], F[i][j - 1], F[i + 1][j - 1]}) + a[i][j];
        }
    }

    int maxSum = -1e9;
    for (int i = 1; i <= n; i++){
        maxSum = max(maxSum, F[i][n]);
    }

    cout << maxSum;

    return 0;
}