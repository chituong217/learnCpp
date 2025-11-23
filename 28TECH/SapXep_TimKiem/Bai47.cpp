#include <iostream>
#define ll long long

using namespace std;

ll k[200005];

bool check(long long time, int n, int t){
    ll totalSum = 0;
    for (ll i = 0; i < n; i++){
        totalSum += time/k[i];
        if (totalSum >= t){
            return true;
        }
    }
    return totalSum >= t;
}

int main(){
    int n, t;
    cin >> n >> t;
    for (int i = 0; i < n; i++){
        cin >> k[i];
    }
    ll left = 0, right = 1e18;
    ll ans = right;
    while (left <= right){
        ll mid = (right - left)/2 + left;
        if (check(mid, n, t)){
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