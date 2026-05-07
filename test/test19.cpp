#include <bits/stdc++.h>
#include <cmath>

using namespace std;

void selectionSort(int a[], int n){
    for (int i = 0; i < n; i++){
        int minPos = i;
        for (int j = i + 1; j < n; j++){
            if (a[j] < a[minPos]){
                minPos = j;
            }
        }

        swap(a[i], a[minPos]);
    }
}

void bubbleSort(int a[], int n){
    for (int i = 0; i < n - 1; i++){
        bool isSwapped = false;
        for (int j = 0; j < n - i - 1; j++){
            if (a[j] > a[j + 1]){
                swap(a[j], a[j + 1]);
                isSwapped = true;
            }
        }
        
        if (isSwapped == false){
            // there is no swap in this loop, means that the array is sorted
            return;
        }
    }
}

void insertionSort(int a[], int n){
    for (int i = 0; i < n; i++){
        int j = i - 1;
        while (j >= 0 && a[j] > a[i]){
            swap(a[i], a[j]);
            j--;
        }
    }
}

void merge(int a[], int left, int mid, int right){
    int n1 = mid - left + 1, n2 = right - mid;
    int x[n1], y[n2];
    
    for (int i = left; i <= mid; i++){
        x[i - left] = a[i];
    }
    for (int i = mid + 1; i <= right; i++){
        y[i - mid - 1] = a[i];
    }

    int i = 0, j = 0, idx = left;
    while (i < n1 && j < n2){
        if (x[i] < y[j]){
            a[idx] = x[i];
            idx++;
            i++;
        }
        else{
            a[idx] = y[j];
            idx++;
            j++;
        }
    }
    while (i < n1){
        a[idx] = x[i];
        idx++;
        i++;
    }
    while (j < n2){
        a[idx] = y[j];
        idx++;
        j++;
    }
}

void mergeSort(int a[], int left, int right){
    if (left < right){
        int mid = (left + right) / 2;

        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);

        merge(a, left, mid, right);
    }
}

void quickSort(int a[], int left, int right){
    if (left < right){
        int pivot = a[(left + right)/2];
        int i = left, j = right;

        while (i <= j){
            while (a[i] < pivot){
                i++;
            }
            while (a[j] > pivot){
                j--;
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

void heapify(int a[], int left, int right){
    int p = left * 2 + 1;

    if (p > right) return;
    if (p + 1 <= right && a[p] < a[p + 1]){
        p = p + 1;
    }

    if (a[left] < a[p]){
        swap(a[left], a[p]);
        heapify(a, p, right);
    }
}

void createHeap(int a[], int n){
    for (int i = (n - 1) / 2; i >= 0; i--){
        heapify(a, i, n - 1);
    }
}

void heapSort(int a[], int n){
    createHeap(a, n);

    for (int i = n - 1; i > 0; i--){
        swap(a[0], a[i]);
        heapify(a, 0, i - 1);
    }
}

int getRadix(int n, int k){
    return (n / (int)(pow(10, k))) % 10;
}

int getNumberLength(int n){
    int len = 0;
    while (n){
        n /= 10;
        len++;
    }

    return len;
}

void radixSort(int a[], int n){
    vector<int> bucket[10];

    int maxVal = INT_MIN;
    for (int i = 0; i < n; i++){
        maxVal = max(maxVal, a[i]);
    }

    int maxLen = getNumberLength(maxVal);
    for(int k = 0; k <= maxLen; k++){
        for (int i = 0; i < n; i++){
            int digit = getRadix(a[i], k);
            bucket[digit].push_back(a[i]);
        }

        int idx = 0;
        for (int i = 0; i < 10; i++){
            for (int x : bucket[i]){
                a[idx] = x;
                idx++;
            }
            bucket[i].clear();
        }
    }
}

int main(){

    return 0;
}