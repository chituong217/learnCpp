#include <iostream>

using namespace std;

bool check(int t, int x, int y, int n){
    int be;
    if (x < y){
        be = x;
    }
    else{
        be = y;
    }
    t -= be;
    int product = 1 + t/x + t/y;
    return product >= n;
}

int main(){
    int n, x, y;
    cin >> n >> x >> y;
    int left = 0, right = 2e8;
    int ans = right;
    while (left <= right){
        int mid = left + (right - left)/2;
        if (check(mid, x, y, n)){
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