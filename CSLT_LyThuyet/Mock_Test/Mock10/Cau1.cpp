#include <iostream>

using namespace std;

bool isPalindromeArray(int* arr, int left, int right){
    if (left >= right){
        return true;
    }

    if (arr[left] == arr[right]){
        return isPalindromeArray(arr, left + 1, right - 1);
    }
    else{
        return false;
    }
}
