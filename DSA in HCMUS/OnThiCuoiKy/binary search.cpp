#include <bits/stdc++.h>

using namespace std;

// Tìm kiếm nhị phân chuẩn trên mảng đã sắp xếp
int binarySearch(int arr[], int n, int target){
    int left = 0, right = n - 1;

    while (left <= right){
        int mid = (left + right) / 2;

        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }

    return -1;
}

// Tìm kiếm phần tử trên mảng xoay vòng đã sắp xếp (Ví dụ: [4, 5, 6, 7, 0, 1, 2])
int searchRotatedArray(int arr[], int n, int target){
    int left = 0, right = n - 1;

    while (left <= right){
        int mid = (left + right) / 2;

        if (arr[mid] == target) return mid;
        
        if (arr[left] < arr[mid]){
            if (arr[left] <= target && target <= arr[mid]){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        else{
            if (arr[mid] <= target && target <= arr[right]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
    }

    return -1;
}