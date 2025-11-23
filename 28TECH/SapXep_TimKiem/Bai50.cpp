#include <iostream>
#define ll long long 

using namespace std;

bool check(ll t, ll x, ll y, ll n){
    ll be;
    if (x < y){
        be = x;
    }
    else{
        be = y;
    }
    if (t < be) return false;
    t -= be;
    ll product = 1 + t/x + t/y;
    return product >= n;
}

int main(){
    ll n, x, y;
    cin >> n >> x >> y;
    ll left = 0, right = 1e18;
    ll ans = right;
    while (left <= right){
        ll mid = left + (right - left)/2;
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