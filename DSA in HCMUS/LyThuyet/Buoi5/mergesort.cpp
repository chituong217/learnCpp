#include <iostream>

using namespace std;

void merge(int a[], int l, int m, int r){
    int n1 = m - l + 1, n2 = r - m;
    int x1[n1], x2[n2];
    for (int i = l; i <= m; i++){
        x1[i - l] = a[i];
    }
    for (int i = m + 1; i <= r; i++){
        x2[i - m - 1] = a[i];
    }

    int i = 0, j = 0, idx = l;
    while (i < n1 && j < n2){
        if (x1[i] < x2[j]){
            a[idx] = x1[i];
            idx++;
            i++;
        }
        else{
            a[idx] = x2[j];
            idx++;
            j++;
        }
    }

    while (i < n1){
        a[idx] = x1[i];
        idx++;
        i++;
    }

    while (j < n2){
        a[idx] = x2[j];
        idx++;
        j++;
    }
}

void mergeSort(int a[], int l, int r){
    if (l < r){
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}


voi quickSort(int a[], int left, int right){
    if (left < right){
        int i = left, j = right, pivot = a[(left + right)/2];

        while (i <= j){
            while (a[i] < pivot){
                i++;
            }
            while (a[j] > pivot){
                i++;
            }

            if (i <= j){
                swap(a[i], a[j]);
                i++;
                j--;
            }
        }

        quickSort(a, left, j);
        quickSort(a, i, right);
    }
}