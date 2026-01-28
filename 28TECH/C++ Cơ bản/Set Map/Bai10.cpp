#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m; cin >> n >> m;
    map <int, int> mp;
    int a[n], b[m];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < m; i++){
        cin >> b[i];
    }
    for (int i = 0; i < n; i++){
        mp[a[i]] = 1;
    }
    for (int i = 0; i < m; i++){
        if (mp[b[i]] == 1){
            mp[b[i]] = 2;
        }
    }
    for (int i = 0; i < n; i++){
        if (mp[a[i]] == 2){
            cout << a[i] << ' ';
            mp[a[i]] = 0;
        }
    }
    return 0;
}