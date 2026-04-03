#include <iostream>

using namespace std;

int binarySearch(int a[], int b[], int n){
    int left = 0, right = n - 2;
    int ans = n - 1;

    while (left <= right){
        int mid = (left + right) / 2;
        if (a[mid] == b[mid]){
            left = mid + 1;
        }
        else{
            ans = mid;
            right = mid - 1;
        }
    }

    return ans + 1;
}

int main(){
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++){
        cin >> b[i];
    }

    cout << binarySearch(a, b, n);

    return 0;
}