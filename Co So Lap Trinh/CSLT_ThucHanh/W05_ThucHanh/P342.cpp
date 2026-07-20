#include <iostream>

#define MAX_LEN 100
using namespace std;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool isMaximum(double a[][MAX_LEN], int i, int j){
    for (int k = 0; k < 8; k++){
        int i1 = i + dx[k], j1 = j + dy[k];
        if (a[i][j] <= a[i1][j1]){
            return false;
        }
    }
    return true;
}

int main(){
    int m, n;
    cin >> m >> n;
    double a[MAX_LEN][MAX_LEN];
    for (int i=0; i < m; i++){
        for (int j=0; j < n; j++){
            cin >> a[i][j];
        }
    }
    int cnt = 0;
    for (int i=1; i<m-1; i++){
        for (int j=1; j<n-1; j++){
            if (isMaximum(a, i, j)){
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}