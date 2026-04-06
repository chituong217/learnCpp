#include <iostream>

using namespace std;

int F[1005][1005];

void solve(int n, int V, int w[], int v[]){
    F[0][0] = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= V; j++){
            if (j >= w[i]){
                F[i][j] = max(F[i - 1][j - w[i]] + v[i], F[i - 1][j]);
            }
            else{
                F[i][j] = F[i - 1][j];
            }
        }
    }
}

int main(){
    int n, V;
    cin >> n >> V;

    int w[n + 1], v[n + 1];
    for (int i = 1; i <= n; i++){
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> v[i];
    }

    solve(n, V, w, v);

    cout << F[n][V];

    return 0;
}