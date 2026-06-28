#include <bits/stdc++.h>

using namespace std;

void merge(int arr[], int left, int mid, int right){
    int n = mid - left + 1, m = right - (mid + 1) + 1;
    int x[n], y[m];

    for (int i = left; i <= mid; i++){
        x[i - left] = arr[i];
    }
    for (int i = mid + 1; i <= right; i++){
        y[i - mid - 1] = arr[i];
    }

    int i = 0, j = 0, idx = left;
    while (i < n && j < m){
        if (x[i] <= y[j]){
            arr[idx++] = x[i++];
        }
        else{
            arr[idx++] = y[j++];
        }
    }
    while (i < n){
        arr[idx++] = x[i++];
    }
    while (j < m){
        arr[idx++] = y[j++];
    }
}


void mergeSort(int arr[], int left, int right){
    if (left < right){
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}