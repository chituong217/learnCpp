#include <iostream>
#include <map>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    int a[n + 1];
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    long long sum = 0;
    int res = 0;
    map<long long, int> mp;
    mp[0] = 0;

    for (int i = 1; i <= n; i++){
        sum += ((a[i] % k) + k) % k;
        sum %= k;

        if (mp.find(sum) != mp.end()){
            res = max(res, i - mp[sum]);
        }
        else{
            mp[sum] = i;
        }
    }

    if (res == 0){
        cout << "-1";
    }
    else{
        cout << res;
    }

    return 0;
}