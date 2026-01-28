#include <iostream>

using namespace std;

long long sumBordersAndDiagonals(int a[][100], int n){
    long long sum = 0;

    // cong bien
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == 0 || j == 0 || i == n - 1 || j == n - 1){
                sum += a[i][j];
            }
        }
    }

    // cong duong cheo chinh
    for (int i = 1; i < n - 1; i++){
        sum += a[i][i];
    }
    
    // cong duong cheo phu
    // neu n la le thi no se bi trung phan tu giua
    if (n % 2 == 1){
        int mid = n / 2;
        sum -= a[mid][mid];
    }

    for (int i = 1; i < n - 1; i++){
        sum += a[i][n - i - 1];
    }
    return sum;
}