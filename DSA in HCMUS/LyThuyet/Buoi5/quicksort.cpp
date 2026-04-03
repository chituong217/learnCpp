#include <iostream>

using namespace std;

int partition(int a[], int left, int right){
    int pivot = a[right];

    int i = left - 1;
    for (int j = left; j <= right; j++){
        if (a[j] < pivot){
            i++;
            swap(a[i], a[j]);
        }
    }

    i++;
    swap(a[r], a[i]);

    return i;
}

void quickSort(int a[], int left, int right){
    if (left < right){
        int pivot = partition(a, left, right);

        quickSort(a, left, pivot - 1);
        quickSort(a, pivot + 1, right);
    }
}

void quickSort2(int a[], int left, int right){
    if (left < right){
        int i = left, j = right;
        int pivot = a[(left + right)/2];
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

        quickSort2(a, left, j);
        quickSort2(a, i, right);
    }
}

int main(){

    return 0;
}