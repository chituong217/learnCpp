#include <iostream>
#include <algorithm>

using namespace std;

int dp[105][105];

int main(){
    int n;
    cin >> n;

    int a[n + 1][n + 1];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            dp[i][j] = max({dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1]}) + a[i][j];
        }
    }

    int maxSum = 0;
    for (int i = 1; i <= n; i++){
        maxSum = max(maxSum, dp[n][i]);
    }

    cout << maxSum;

    return 0;
}