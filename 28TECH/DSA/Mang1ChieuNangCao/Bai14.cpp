#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool isSoKhongGiam(int n){
    int prev = 10;

    while (n > 0){
        if (prev < n % 10){
            return false;
        }
        prev = n % 10;
        n /= 10;
    }

    return true;
}

bool comp(pair<int,int> a, pair<int,int> b){
    if (a.second > b.second){
        return true;
    }
    else if (a.second < b.second){
        return false;
    }
    else{
        if (a.first < b.first){
            return true;
        }
        else{
            return false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<int, int> mp;

    int tmp;
    while (cin >> tmp){
        if (isSoKhongGiam(tmp) == true){
            mp[tmp]++;
        }
    }

    vector <pair<int,int>> v(mp.begin(), mp.end());
    sort(v.begin(), v.end(), comp);

    for (auto it = v.begin(); it != v.end(); it++){
        cout << it->first << ' ' << it->second << '\n';
    }

    return 0;
}