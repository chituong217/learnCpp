#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    int n;
    cin >> n;

    map<int,int> mp;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }

    long long cnt = 0;
    for (auto it = mp.begin(); it != mp.end(); it++){
        int freq = it->second;

        cnt += 1ll * (freq) * (freq - 1) / 2;
    }
    
    cout << cnt;

    return 0;
}