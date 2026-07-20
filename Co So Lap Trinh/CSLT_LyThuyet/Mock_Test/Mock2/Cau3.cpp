#include <iostream>

using namespace std;

int countQueens(int a[][100], int N){
    int countQueens = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            bool isQueen = true;
            for (int k = 0; k < N; k++){
                if (a[i][j] < a[k][j]){
                    isQueen = false; 
                    break;
                }
            }
            for (int k = 0; k < N; k++){
                if (a[i][j] < a[i][k]){
                    isQueen = false;
                    break;
                }
            }
            if (isQueen){
                countQueens++;
            }
        }
    }
    return countQueens;
}