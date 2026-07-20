#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    //yeucau1
    auto it = lower_bound(a, a + n, x);
    if (it != (a+n)){
        cout << it - a << endl;
    }
    else{
        cout << "-1" << endl;
    }
    //yeucau2
    it = upper_bound(a, a + n, x);
    if (it != (a+n)){
        cout << it - a << endl;
    }
    else{
        cout << "-1" << endl;
    }
    //yeucau3
    int left = 0, right = n - 1;
    int first = -1;
    while (left <= right){
        int mid = left + (right - left)/2;
        if (a[mid] == x){
            first = mid;
            right = mid - 1;
        }
        else if (a[mid] < x){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    cout << first << endl;
    // yeucau4
    left = 0;
    right = n - 1;
    int last = -1;
    while (left <= right){
        int mid = left + (right - left)/2;
        if (a[mid] == x){
            last = mid;
            left = mid + 1;
        }
        else if (a[mid] < x){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    cout << last << endl;
    //yeucau5
    if (first == -1){
        cout << "0" << endl;
    }
    else{
        cout << last - first + 1 << endl;
    }
    return 0;
}