#include <iostream>

using namespace std;

int findNumberKTimesPerRow(int a[][100], int M, int N, int K){
    (void)M;
    for (int i = 0; i < N; i++){
        int current = a[0][i];
        int cnt = 0;
        for (int j = 0; j < N; j++){
            if (a[0][j] == current){
                cnt++;
            }
        }
        if (cnt == K){
            return current;
        }
    }
    return 0;
}

int main(){
    int M, N, K;
    cin >> M >> N >> K;
    int a[100][100];
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            cin >> a[i][j];
        }
    }
    cout << findNumberKTimesPerRow(a, M, N, K);
    return 0;
}