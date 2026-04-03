#include <iostream>

using namespace std;

int binarySearch(int a[], int n, int k){
    int left = 0, right = n - 1;

    while (left <= right){
        int mid = (left + right) / 2;

        if (a[mid] == k){
            return 1;
        }
        else if (a[mid] < k){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return -1;
}

int main(){
    int n, k;
    cin >> n >> k;

    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    if (binarySearch(a, n, k) == 1){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}