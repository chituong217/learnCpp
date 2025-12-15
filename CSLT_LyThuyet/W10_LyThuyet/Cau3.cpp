#include <iostream>
#include <cstring>

using namespace std;

long long chuyendoidodai(char a[]){
    int len = strlen(a);
    long long sum = 0;
    for (int i = 0; i < len; i++){
        int snguyen = (int)a[i] - (int)'a';
        if (snguyen < 10){
            sum = sum * 10 + 1ll * snguyen;
        }
        else{
            sum = sum * 100 + 1ll * snguyen;
        }
    }

    return sum;
}

bool checkEqual(char first[], char second[], char target[]){
    long long firstI = chuyendoidodai(first);
    long long secondI = chuyendoidodai(second);
    long long targetI = chuyendoidodai(target);

    return firstI + secondI == targetI;
}