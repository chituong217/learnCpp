#include <iostream>

using namespace std;

int sumLowerTriangular(int** matrix, int n){
    int sum = 0;
    for (int i = 0; i < n; i++){
        for (int j  = 0; j < n; j++){
            if (i >= j){
                sum += matrix[i][j];
            }
        }
    }

    return sum;
}