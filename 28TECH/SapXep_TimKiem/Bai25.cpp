#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int,int> a, pair<int, int> b){
    if (a.first < b.first){
        return true;
    }
    else if (a.first == b.first){
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

int main(){
    int n; 
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), comp);
    long long tmp_end = 0;
    for (int i = 0; i < n; i++){
        if (tmp_end < a[i].first){
            tmp_end = a[i].first;
        } 
        tmp_end += a[i].second;
    }
    cout << tmp_end << endl;
    return 0;
}