#include <iostream>

using namespace std;

int m, n;
int a[100][100];
bool X[100][100] = {false};
int cnt = 0;

void Try(int i, int j){
    if (i == m && j == n){
        cnt++;
    }

    if (i + 1 <= m && X[i + 1][j] == true){
        X[i + 1][j] = false;

        Try(i + 1, j);

        X[i + 1][j] = true;
    }
    if (j + 1 <= n && X[i][j + 1] == true){         
        X[i][j + 1] = false;

        Try(i, j + 1);

        X[i][j + 1] = true;
    }
}

int main(){
    cin >> m >> n;

    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
            X[i][j] = true;
        }
    }

    Try(1, 1);
    cout << cnt;

    return 0;
}