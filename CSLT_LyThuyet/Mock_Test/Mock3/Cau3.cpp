#include <iostream>

using namespace std;

void findSaddlePoints(int a[][100], int rows, int cols){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            bool isReal = true;
            // nho nhat tren dong
            for (int k = 0; k < cols; k++){
                if (a[i][k] < a[i][j]) isReal = false;
            }
            // lon nhat tren cot
            for (int k = 0; k < rows; k++){
                if (a[k][j] > a[i][j]) isReal = false;
            }
            if (isReal == true){
                cout << "(" << i << << ", " << j << ")" << endl;
            }
        }
    }
}