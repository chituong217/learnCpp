#include <iostream>

using namespace std;

void solve(int a[], int n, int k){
    int sum = 0;
    for (int i = 0; i < k; i++){
        sum += a[i];
    }

    int maxStart = 0;
    int maxSum = sum;

    for (int i = k; i < n; i++){
        sum += a[i];
        sum -= a[i - k];

        if (maxSum < sum){
            maxSum = sum;
            maxStart = i - k + 1;
        }
    }

    cout << maxStart << ' ' << maxSum << endl;
}

int main(){
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    solve(a, n, k);

    return 0;
}