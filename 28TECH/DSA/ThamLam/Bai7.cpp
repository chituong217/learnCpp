#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int,int> a, pair<int,int> b){
    if (a.second < b.second){
        return true;
    }
    else if (a.second == b.second){
        return a.first > b.first;
    }
    else{
        return false;
    }
}

int main(){
    int n;
    cin >> n;

    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), comp);

    // cout << "KET QUA :" << endl;
    // for (int i = 0; i < n; i++){
    //     cout << v[i].first << ' ' << v[i].second << endl;
    // }

    int cnt = 0;
    int end = 0;
    for (int i = 0; i < n; i++){
        if (v[i].first > end){
            cnt++;
            end = v[i].second;
        }
    }

    cout << cnt;

    return 0;
}