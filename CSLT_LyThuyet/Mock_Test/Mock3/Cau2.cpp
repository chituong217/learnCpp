#include <iostream>

using namespace std;

void rotateArray (int* nums, int size, int k){
    int tmp[size];
    int tmpIdx = 0;
    int k = k % size;
    for (int i = size - k; i < size; i++){
        tmp[tmpIdx] = nums[i];
        tmpIdx++;
    }
    for (int i = 0; i < size - k; i++){
        tmp[tmpIdx] = nums[i];
        tmpIdx++;
    }
    for (int i = 0; i < size; i++){
        nums[i] = tmp[i];
    }
}