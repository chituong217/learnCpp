#include <iostream>

using namespace std;

int main(){
    int n, x;
    cin >> n >> x;

    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int res = -1;
    int left = 0, right = n - 1;
    while (left <= right){
        int mid = (left + right) / 2;

        if (a[mid] <= x){
            res = a[mid];
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    cout << res;

    return 0;
}