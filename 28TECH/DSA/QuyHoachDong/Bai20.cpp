#include <iostream>
#include <algorithm>

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
            if (a[i][j] == 1){
                F[i][j] = min({F[i - 1][j], F[i][j - 1], F[i - 1][j - 1]}) + 1;
            }
        }
    }

    int maxSquare = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            maxSquare = max(maxSquare, F[i][j]);
        }
    }

    cout << maxSquare;

    return 0;
}