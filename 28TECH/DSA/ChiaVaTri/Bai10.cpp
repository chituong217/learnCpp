#include <iostream>

using namespace std;

int binarySearchIndex0(int a[], int n){
    int left = 0, right = n - 1;
    int ans = -1;

    while (left <= right){
        int mid = (left + right) / 2;
        if (a[mid] == 1){
            right = mid - 1;
        }
        else{
            ans = mid;
            left = mid + 1;
        }
    }

    return ans;
}

int main(){
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int lastIndex = binarySearchIndex0(a, n);
    cout << lastIndex + 1;

    return 0;
}