#include <iostream>
#include <set>
#include <map>

using namespace std;

int main(){
    map<int, int> mp;
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        int tmp; cin >> tmp;
        mp[tmp]++;
    }
    cout << mp.size() << endl;
    return 0;
}