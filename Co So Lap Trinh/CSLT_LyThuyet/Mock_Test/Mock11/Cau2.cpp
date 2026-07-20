#include <iostream>

using namespace std;

int** transposeMatrix(int** matrix, int rows, int cols){
    int** newMatrix = new int*[cols];
    for (int i = 0; i < cols; i++){
        newMatrix[i] = new int[rows];
    }

    for (int i = 0; i < cols; i++){
        for (int j = 0; j < rows; j++){
            newMatrix[i][j] = matrix[j][i];
        }
    }

    return newMatrix;
}