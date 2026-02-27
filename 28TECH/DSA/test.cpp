#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <set>
#include <map>
#include <string>
#include <algorithm>


using namespace std;

void selectionSort(int a[], int n){
    for (int i = 0; i < n; i++){
        int min_pos = i;
        for (int j = i + 1; j < n; j++){
            if (a[j] < a[min_pos]){
                min_pos = j;
            }
        }

        swap(a[min_pos], a[i]);
    }
}

void bubbleSort(int a[], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (a[j] > a[j + 1]){
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void insertionSort(int a[], int n){
    for (int i = 0; i < n; i++){
        int j = i;
        while (j > 0 && a[j] < a[j - 1]){
            swap(a[j], a[j - 1]);
            j--;
        }
    }
}

int counting[10000009];

void countingSortAndPrinting(int a[], int n){
    int max_val = INT_MIN;
    for (int i = 0; i < n; i++){
        max_val = max(max_val, a[i]);
    }
    for (int i = 0; i < n; i++){
        counting[a[i]]++;
    }

    for (int i = 0; i <= max_val; i++){
        while (counting[i] > 0){
            cout << i << ' ';
            counting[i]--; 
        }
    }
}


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

int partition(int a[], int l, int r){
    int pivot = a[r];
    int i = l - 1;
    for (int j = l; j < r; j++){
        if (a[j] < pivot){
            i++;
            swap(a[i], a[j]);
        }
    }
    i++;
    swap(a[i], a[r]);
    return i;
}

void quickSort(int a[], int l, int r){
    if (l >= r){
        return;
    }

    int pivot = partition(a, l, r);
    quickSort(a, l, pivot - 1);
    quickSort(a, pivot + 1, r);
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    quickSort(a, 0, n - 1);

    for (int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }

    return 0;
}