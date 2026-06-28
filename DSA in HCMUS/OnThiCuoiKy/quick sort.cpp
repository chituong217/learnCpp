#include <bits/stdc++.h>

using namespace std;

// Phân hoạch Lomuto (chọn chốt là phần tử cuối)
int partitionLomuto(int arr[], int low, int high){
    int pivot = arr[high];

    int i = low - 1;
    for (int j = low; j < high; j++){
        if (arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }

    i++;
    swap(arr[i], arr[high]);
    return i;
}

void quickSort(int arr[], int low, int high){
    if (low > high) return;

    int i = low, j = high;
    while (i <= j){
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i <= j){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    quickSort(arr, low, j);
    quickSort(arr, i, high);
}