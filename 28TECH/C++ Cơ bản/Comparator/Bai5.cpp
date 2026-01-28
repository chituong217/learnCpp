#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair< pair<int, int>, int > a, pair< pair<int, int>, int > b){
    if (a.first.first < b.first.first){
        return true;
    }
    else if (a.first.first == b.first.first){
        if (a.first.second < b.first.second){
            return true;
        }
        else if (a.first.second == b.first.second){
            if (a.second < b.second){
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
    else{
        return false;
    }
}

int main(){
    int n;
    cin >> n;
        vector< pair< pair<int, int>, int > > v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i].first.first >> v[i].first.second >> v[i].second;
    }
    sort(v.begin(), v.end(), comp);
    for (int i = 0; i < n; i++){
        cout << v[i].first.first << " " << v[i].first.second << " " << v[i].second << endl;
    }

    return 0;
}