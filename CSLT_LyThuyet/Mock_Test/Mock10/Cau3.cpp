#include <iostream>
#include <cstdlib>

using namespace std;

void sortMainDiagonal(int** matrix, int n){
    int* line = new int[n];

    for (int i = 0; i < n; i++){
        line[i] = matrix[i][i];
    }

    for (int i = 0; i < n; i++){
        int min = i;
        for (int j = i + 1; j < n; j++){
            if (line[min] > line[j]){
                min = j;
            }
        }

        int tmp = line[min];
        line[min] = line[i];
        line[i] = tmp;
    }

    for (int i = 0; i < n; i++){
        matrix[i][i] = line[i];
    }

    delete []line;
}