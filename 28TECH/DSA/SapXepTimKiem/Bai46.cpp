#include <iostream>

using namespace std;

bool check(int a[], int n, int k, long long sum){
    int cnt = 1;

    long long currSum = a[0];
    for (int i = 1; i < n; i++){
        if (a[i] > sum){
            return false;
        }
        if (currSum + a[i] > sum){
            cnt++;
            currSum = a[i];
        }
        else{
            currSum += a[i];
        }
    }

    return cnt <= k;
}

int main(){
    int n, k;
    cin >> n >> k;
    int a[n];

    long long left = 0, right = 0;

    for (int i = 0; i < n; i++){
        cin >> a[i];
        right += a[i];
        if (a[i] > left){
            left = a[i];
        }
    }

    long long ans = -1;

    while (left <= right){
        long long mid = (left + right)/2;

        if (check(a, n, k, mid) == true){
            ans = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }

    cout << ans;

    return 0;
}