#include <iostream>
#include <vector>

using namespace std;

int getDigit(int n, int exp){
    return (n / exp) % 10;
}

void radixSort(int a[], int n){
    vector<int> bucket[10];

    int maxVal = INT_MIN;
    for (int i = 0; i < n; i++){
        maxVal = max(maxVal, a[i]);
    }

    for (int exp = 1; (maxVal / exp) != 0; exp *= 10){
        for (int i = 0; i < n; i++){
            int digit = getDigit(a[i], exp);
            bucket[digit].push_back(a[i]);
        }

        int idx = 0;
        for (int i = 0; i < 10; i++){
            for (int x : bucket[i]){
                a[idx++] = x;
            }

            bucket[i].clear();
        }
    }
}

int solve(int a[], int n, int k){
    radixSort(a, n);

    int chenhlech = INT_MAX;
    for (int i = 0; i < n - k + 1; i++){
        int left = i, right = i + k - 1;

        if (chenhlech > a[right] - a[left]){
            chenhlech = a[right] - a[left];
        }
    }

    return chenhlech;
}

int main(){
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    cout << solve(a, n, k);

    return 0;
}