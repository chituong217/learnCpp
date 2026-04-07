#include <iostream>
#include <map>
#define ll long long

using namespace std;

int main(){
    int n;
    cin >> n;

    map<int, int> mp;
    ll cnt = 0;
    int a[n + 1];
    int t = 0;
    mp[0] = 1;

    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i] % 2 == 0){
            t++;
        }
        else{
            t--;
        }

        cnt += mp[t];
        mp[t]++;
    }

    cout << cnt;

    return 0;
}