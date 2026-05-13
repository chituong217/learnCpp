#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int ke[n][n];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            ke[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++){
        int dau, cuoi;
        cin >> dau >> cuoi;
        ke[dau - 1][cuoi - 1] = 1;
        ke[cuoi - 1][dau - 1] = 1;
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << ke[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}