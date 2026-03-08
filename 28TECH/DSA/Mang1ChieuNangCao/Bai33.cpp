#include <iostream>
#include <map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;

    int a[n + 1];
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    map <long long, int> mp;
    mp[0] = 0;
    long long sum = 0;
    int res = 1e9;
    for (int i = 1; i <= n; i++){
        sum += a[i];

        if (mp.count(sum - k) > 0){
            res = min(res, i - mp[sum - k]);
        }
        mp[sum] = i;
    }

    if (res != 1e9){
        cout << res;
    }
    else{
        cout << "-1";
    }

    return 0;
}