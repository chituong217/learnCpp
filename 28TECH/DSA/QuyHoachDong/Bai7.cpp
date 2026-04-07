#include <iostream>

using namespace std;

int F[105][25005];

int main(){
    int c, n;
    cin >> c >> n;

    int w[n + 1];
    for (int i = 1; i <= n; i++){
        cin >> w[i];
    }

    F[0][0] = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= c; j++){
            if (w[i] <= j){
                F[i][j] = max(F[i - 1][j - w[i]] + w[i], F[i - 1][j]);
            }
            else{
                F[i][j] = F[i - 1][j];
            }
        }
    }

    cout << F[n][c];

    return 0;
}