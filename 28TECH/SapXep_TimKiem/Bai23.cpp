#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int fre[1000005] = {0};

bool comp(pair<int, int> a, pair<int, int> b){
    if (a.second > b.second){
        return true;
    }
    else if (a.second == b.second){
        if (a.first < b.first){
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

bool comp2(pair<int, int> a, pair<int, int> b){
    if (a.second > b.second){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        fre[a[i]]++;
    }

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++){
        if(fre[a[i]] > 0){
            v.push_back({a[i], fre[a[i]]});
            fre[a[i]] = 0;
        }
    }

    vector<pair<int, int>> v2;
    for (int i = 0; i < (int)v.size(); i++){
        v2.push_back(v[i]);
    }

    sort(v.begin(), v.end(), comp);
    for (int i = 0; i < (int)v.size(); i++){
        int fre = v[i].second;
        while (fre){
            cout << v[i].first << ' ';
            fre--;
        }
    }
    cout << endl;

    stable_sort(v2.begin(), v2.end(), comp2);
    for (int i = 0; i < (int)v2.size(); i++){
        int fre = v2[i].second;
        while (fre){
            cout << v2[i].first << ' ';
            fre--;
        }
    }

    return 0;
}