#include <iostream>
#define ll long long
using namespace std;

bool check(ll mid, ll a, ll b, ll n){
    ll col = mid/a;
    ll row = mid/b;
    if (col >= n || row >= n){
        return true;
    }
    if (row > 0 && col > n/row){
        return true;
    }
    return col*row >= n;
}

int main(){
    ll a, b, n;
    cin >> a >> b >> n;
    ll left = 1, right = 1e18;
    ll ans = right;
    while (left <= right){
        ll mid = left + (right-left)/2;
        if (check(mid, a, b, n)){
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