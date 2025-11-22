#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
    if (a.first < b.first){
        return true;
    }
    else if (a.first == b.first){
        if (a.second > b.second){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

int main(){
    int n, s;
    cin >> n >> s;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        a[i] = {x, y};
    }
    sort(a.begin(), a.end(), comp);

    bool isWin = true;
    for (int i = 0; i < n; i++){
        if (s > a[i].first){
            s += a[i].second;
        }
        else{
            isWin = false;
            break;
        }
    }
    if (isWin == true){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}