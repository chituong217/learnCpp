#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<char> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    vector<pair<char, int>> dem;
    for (int i = 0; i < n; i++){
        bool found = false;
        for (int j = 0; j < (int)dem.size(); j++){
            if (dem[j].first == v[i]){
                dem[j].second++;
                found = true;
                break;
            }
        }
        if (found == false){
            pair<char, int> tmp = {v[i], 1};
            dem.push_back(tmp);
        }
    }
    
    cout << dem.size() << endl;
    for (int i = 0; i < (int)dem.size(); i++){
        cout << dem[i].first << ' ' << dem[i].second << endl;
    }

    return 0;
}