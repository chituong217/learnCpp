#include <iostream>

using namespace std;

void multiplyMatrices(int A[][100], int B[][100], int C[][100], int m, int p, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            C[i][j] = 0;
            for (int k = 0; k < p; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}