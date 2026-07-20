#include <iostream>
#include <map>

using namespace std;

int main(){
    map<int, int> mp;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        mp[tmp]++;
    }
    for (auto it = mp.begin(); it != mp.end(); it++){
        if (it->second %2 == 0){
            cout << it->first << ' ' << it->second << endl;
        }
    }
    cout << endl;
    for (auto it = mp.rbegin(); it != mp.rend(); it++){
        if (it->second %2 == 0){
            cout << it->first << ' ' << it->second << endl;
        }
    }
    return 0;
}