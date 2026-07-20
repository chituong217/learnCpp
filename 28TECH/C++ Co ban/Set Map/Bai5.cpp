#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    map<char, int> mp;
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        char tmp; cin >> tmp;
        mp[tmp]++;
    }
    // 1
    auto dautien = mp.begin();
    cout << (*dautien).first << ' ' << (*dautien).second << endl;
    cout << endl;
    // 2
    auto cuoicung = mp.rbegin();
    cout << (*cuoicung).first << ' ' << (*cuoicung).second << endl;
    cout << endl;
    // 3
    for (auto it = mp.begin(); it != mp.end(); it++){
        cout << it->first << ' ' << it->second << endl;
    }
    cout << endl;
    // 4
    for (auto it = mp.rbegin(); it != mp.rend(); it++){
        cout << it->first << ' ' << it->second << endl;
    }
    return 0;
}