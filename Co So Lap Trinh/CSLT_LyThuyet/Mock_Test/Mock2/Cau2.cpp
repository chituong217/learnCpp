#include <iostream>

using namespace std;

int findLongestAlternatingSubarray(int* nums, int size){
    int longest = 0;
    int i = 1;
    while (i < size){
        int currentLength = 1;
        if (nums[i] * nums[i - 1] < 0){
            while (i < size && nums[i] * nums[i-1] < 0){
                i++;
                currentLength++;
            }
        }
        else{
            i++;
        }
        if (currentLength > longest){
            longest = currentLength;
        }
    }
    return longest;
}