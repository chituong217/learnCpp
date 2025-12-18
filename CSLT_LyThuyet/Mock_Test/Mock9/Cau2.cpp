#include <iostream>

using namespace std;

void findSaddlePoints(int** matrix, int n){

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            bool isSaddlePoint = true;

            for (int col = 0; col < n; col++){
                if (matrix[i][col] <= matrix[i][j] && col != j){
                    isSaddlePoint = false;
                }
            }

            for (int row = 0; row < n; row ++){
                if (matrix[row][j] >= matrix[i][j] && row != i){
                    isSaddlePoint = false;
                }
            }

            if (isSaddlePoint == true){
                cout << "(" << i << ", " << j << ")\n";
            }
        }
    }
}