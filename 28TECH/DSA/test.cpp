#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <set>
#include <map>
#include <string>


using namespace std;

int main(){
    map<int, int> mp;
    mp.insert({1, 2}); // insert vao cap {1, 2}
    mp.insert({2, 3});
    mp.insert({3, 4});
    mp.insert({5, 2});
    mp.insert({1, 5}); // do trong map da co key 1 roi nen se khong insert nua

    cout << mp.size() << endl; // 4

    mp[1] = 3; // key 1 bay gio co value la 3
    mp[4] = 2; // them cap {4, 2}

    cout << mp.size() << endl; // 5
    cout << mp[5] << endl; // value cua key 5

    for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++){
        // cout << (*it).first << ' ' << (*it).second << endl;
        cout << it->first << ' ' << it->second << endl;
    }
    
    return 0;
}