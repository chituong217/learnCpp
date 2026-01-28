#include <iostream>
#include <map>

using namespace std;

int main(){
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int tmp;
            cin >> tmp;
            if (mp[tmp] == i){
                mp[tmp]++;
            }
        }
    }
    bool isFound = false;
    for (auto it = mp.begin(); it != mp.end(); it++){
        if (it->second >= n){
            cout << it->first << ' ';
            isFound = true;
        }
    }
    if (isFound == false){
        cout << "NOT FOUND" << endl;
    }
    return 0;
}