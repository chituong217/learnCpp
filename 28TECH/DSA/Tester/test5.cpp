#include <iostream>

using namespace std;

bool check(int a[], int n, int l, int h){
    long long tong = 0;
    for (int i = 0; i < n; i++){
        if (a[i] >= h){
            tong += (a[i] - h);
        }
    }

    return tong >= l;
}

int main(){
    int n, l;
    cin >> n >> l;

    int left = 0, right = 0;

    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        right = max(right, a[i]);
    }

    int ans = -1;
    while (left <= right){
        int mid = (left + right)/2;

        if (check(a, n, l, mid) == true){
            ans = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    cout << ans;

    return 0;
}