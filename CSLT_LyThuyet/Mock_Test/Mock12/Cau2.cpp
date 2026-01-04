#include <iostream>

using namespace std;

int binarySearchRecursive(int* arr, int left, int right, int x){
    if (left > right){
        return -1;
    }
    
    int mid = (right + left) / 2;
    
    if (arr[mid] == x){
        return 1;
    }
    else if (arr[mid] > x){
        return binarySearchRecursive(arr, left, mid - 1, x);
    }
    else{
        return binarySearchRecursive(arr, mid + 1, right, x);
    }
}