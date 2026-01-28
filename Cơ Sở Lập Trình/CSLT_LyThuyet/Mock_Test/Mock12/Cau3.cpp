#include <iostream>

using namespace std;

int** rotateMatrix90(int** matrix, int n){
    int** newMatrix = new int*[n];
    for (int i = 0; i < n; i++){
        newMatrix[i] = new int[n];
    }

    for (int j = 0; j < n; j++){
        for (int i = n - 1; i >= 0; i--){
            newMatrix[j][n - 1 - i] = matrix[i][j];
        }
    }

    return newMatrix;
}