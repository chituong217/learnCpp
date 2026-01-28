#include <iostream>
#define MAX_LEN 100

using namespace std;

bool isYenNgua(int a[][MAX_LEN], int m, int n, int i, int j){
    for (int k = 0; k < n; k++){
        if (a[i][j] < a[i][k]){
            return false;
        }
    }
    for (int k = 0; k < m; k++){
        if (a[i][j] > a[k][j]){
            return false;
        }
    }
    return true;
}

int main(){
    int a[MAX_LEN][MAX_LEN];
    int m, n;
    cin >> m >> n;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }

    int cnt = 0;
    for (int i=0; i<m; i++){
        for (int j = 0; j < n; j++){
            if (isYenNgua(a, m, n, i, j)){
                cnt++;
            }
        }
    }
    cout << cnt;

    return 0;
}