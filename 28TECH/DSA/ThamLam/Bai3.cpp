#include <iostream>
#include <algorithm>
#define mod 1000000007

using namespace std;

int partition(int a[], int left, int right){
    int pivot = a[right];
    int i = left - 1;
    
    for (int j = left; j < right; j++){
        if (a[j] < pivot){
            i++;
            swap(a[i], a[j]);
        }
    }

    i++;
    swap(a[right], a[i]);

    return i;
}

void quickSort(int a[], int left, int right){
    if (left < right){
        int pivot = partition(a, left, right);

        quickSort(a, left, pivot - 1);
        quickSort(a, pivot + 1, right);
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a, a + n);
    long long sum = 0;
    for (int i = 0; i < n; i++){
        sum += ((1ll * i * a[i]) % mod);
        sum %= mod;
    }

    cout << sum;

    return 0;
}