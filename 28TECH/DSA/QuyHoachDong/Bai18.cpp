#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

int F[505][505];

int main(){
    int n, m;
    cin >> n >> m;

    int a[n + 1][m + 1];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            F[i][j] = a[i][j];
            F[i][j] += max({F[i - 1][j], F[i][j - 1], F[i - 1][j - 1]});
        }
    }

    cout << F[n][m];

    return 0;
}