#include <iostream>

using namespace std;

bool isMagicSquare(int a[][100], int n){
    int check[10005];

    // khoi tao mang check = 0
    for (int i = 1; i <= n*n +1; i++){
        check[i] = 0;
    }
    
    // check xem co du tu 1 den n*n ko
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            check[a[i][j]] = 1;
        }
    }

    for (int i = 1; i <= n*n; i++){
        if (check[i] == 0){
            return false;
        }
    }

    // check xem tong co bang nhau ko
    long long sum = 0;
    for (int i = 0; i < n; i++){
        sum += a[0][i];
    }
    // hang
    for (int i = 1; i < n; i++){
        long long rowSum = 0;
        for (int j = 0; j < n; j++){
            rowSum += a[i][j];
        }
        if (rowSum != sum) return false;
    }
    // cot
    for (int j = 0; j < n; j++){
        long long colSum = 0;
        for (int i = 0; i < n; i++){
            colSum += a[i][j];
        }
        if (colSum != sum) return false;
    }
    // cheo
    long long sumCheoChinh = 0;
    long long sumCheoPhu = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == j){
                sumCheoChinh += a[i][j];
            }
            if (i + j == n - 1){
                sumCheoPhu += a[i][j];
            }
        }
    }
    if (sumCheoChinh != sum || sumCheoPhu != sum) return false;

    return true;
}