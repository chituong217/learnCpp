#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    map<int, int> mp;
    vector<int> dem;
    for (int i = 0; i < n; i++){
        int tmp; cin >> tmp;
        mp[tmp]++;
        dem.push_back(mp[tmp]);
    }
    for (int i = 0; i < (int)dem.size(); i++){
        cout << dem[i] << ' ';
    }
    return 0;
}