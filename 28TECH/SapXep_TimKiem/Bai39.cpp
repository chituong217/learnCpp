#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair <int,int> a, pair <int,int> b){
    if (a.second < b.second){
        return true;
    }
    else if (a.second == b.second){
        return a.first < b.first;
    }
    else{
        return false;
    }
}

int main(){
    int n;
    cin >> n;
    vector <pair <int,int> > a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), comp);
    int current_end = 0;
    int maxFilmNumbers = 0;
    for (int i = 0; i < n; i++){
        if (a[i].first >= current_end){
            current_end = a[i].second;
            maxFilmNumbers++;
        }
    }
    cout << maxFilmNumbers;
    return 0;
}