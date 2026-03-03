#include <iostream>
#include <algorithm>

using namespace std;

int binarySearch(int a[], int left, int right, int x){
    if (left <= right){
        int mid = (left + right)/2;
        if (a[mid] == x){
            return mid;
        }
        else if (a[mid] > x){
            return binarySearch(a, left, mid - 1, x);
        }
        else{
            return binarySearch(a, mid + 1, right, x);
        }
    }
    else{
        return -1;
    }
}

int main(){
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a, a + n);

    bool ok = false;
    for (int i = 0; i < n; i++){
        int find = k - a[i];

        int bS = binarySearch(a, 0, n - 1, find);
        if (bS != -1 && bS != i){
            ok = true;
            break;
        }
    }

    if (ok == true){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}