#include <iostream>

using namespace std;

void quickSort(int a[], int left, int right){
    if (left < right){
        int i = left, j = right, pivot = a[(left + right)/2];
        while (i <= j){
            while (a[i] < pivot) i++;
            while (a[j] > pivot) j--;

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

int main(){
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    quickSort(a, 0, n - 1);

    long long currentTime = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++){
        if (currentTime <= a[i]){
            currentTime += a[i];
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}