#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int left = 0;
    int right = n-1;
    int cnt = 0;
    while (left <= right){
        if (left == right){
            cnt++;
            break;
        }
        if (a[right] + a[left] > x){
            right--;
            cnt++;
        }
        else{
            right--;
            left++;
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}