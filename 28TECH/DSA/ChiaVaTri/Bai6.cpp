#include <iostream>
#include <algorithm>

using namespace std;

long long findLargestSumMid(int a[], int l, int m, int r){
    long long leftSum = -1e18;
    long long sum = 0;
    for (int i = m; i >= l; i--){
        sum += a[i];
        if (sum > leftSum){
            leftSum = sum;
        }
    }

    long long rightSum = -1e18;
    sum = 0;
    for (int i = m + 1; i <= r; i++){
        sum += a[i];
        if (sum > rightSum){
            rightSum = sum;
        }
    }

    return leftSum + rightSum;
}

long long findMaxSum(int a[], int l, int r){
    if (l == r){
        return a[l];
    }

    int m = (l + r)/2;
    return max({findMaxSum(a, l, m), findLargestSumMid(a, l, m, r), findMaxSum(a, m + 1, r)});
}

int main(){
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    cout << findMaxSum(a, 0, n - 1);

    return 0;
}