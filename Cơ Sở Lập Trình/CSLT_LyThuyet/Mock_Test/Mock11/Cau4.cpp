#include <iostream>

using namespace std;

int findMaxRecursive(int* arr, int n){
    if (n == 1){
        return arr[0];
    }

    int maxTruoc = findMaxRecursive(arr, n - 1);
    if (arr[n - 1] > maxTruoc){
        return arr[n - 1];
    }
    else{
        return maxTruoc;
    }
}