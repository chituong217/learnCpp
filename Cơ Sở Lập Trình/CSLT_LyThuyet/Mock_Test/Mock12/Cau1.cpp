#include <iostream>

using namespace std;

void moveEvensToFront(int* arr, int n){
    if (arr == NULL){
        return;
    }

    int left = 0;
    int right = n - 1;
    while (left < right){
        if (arr[left] % 2 == 0 && arr[right] % 2 == 0){
            left++;
        }
        else if (arr[left] % 2 == 1 && arr[right] % 2 == 1){
            right--;
        }
        else if (arr[left] % 2 == 1 && arr[right] % 2 == 0){
            int tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;

            left++;
            right--;
        }
        else{
            left++;
            right--;
        }
    }
}