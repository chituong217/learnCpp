#include <iostream>

using namespace std;

void createSpriralMatrix(int a[][100], int N){
    int c1 = 0, c2 = N - 1, h1 = 0, h2 = N - 1;
    int cnt = 1;
    while (cnt <= N*N){
        for (int i = c1; i <= c2; i++){
            a[h1][i] = cnt;
            cnt++;
        }
        h1++;
        for (int i = h1; i <= h2; i++){
            a[i][c2] = cnt;
            cnt++;
        }
        c2--;
        for (int i = c2; i >= c1; i--){
            a[h2][i] = cnt;
            cnt++;
        }
        h2--;
        for (int i = h2; i >= h1; i--){
            a[i][c1] = cnt;
            cnt++;
        }
        c1++;
    }
}

int main(){
    int n;
    cin >> n;
    int a[100][100];
    createSpriralMatrix(a, n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}