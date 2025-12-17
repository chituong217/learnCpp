#include <iostream>

using namespace std;

long long sumMaxArrayKLength(int a[], int n, int k){
    long long currentWindowSum = 0;
    if (k > n) return 0;
    for (int i = 0; i < k; i++){
        currentWindowSum += a[i];
    }
    long long maxWindowSum = currentWindowSum;
    for (int i = k; i < n; i++){
        currentWindowSum = currentWindowSum + a[i] - a[i - k];

        if (currentWindowSum > maxWindowSum){
            maxWindowSum = currentWindowSum;
        }
    }

    return maxWindowSum;
}

int main(){
    int n, k;
    cin >> n >> k;
    int a[1000];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    cout << sumMaxArrayKLength(a, n, k);
    return 0;
}