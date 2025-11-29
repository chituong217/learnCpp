#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

ll tinhBinhPhuongKhoangCachSoVoiGocToaDo(pair<int,int> a){
    ll distance = 1ll * a.first * a.first + 1ll * a.second * a.second;
    return distance;
}

bool comp(pair<int,int> a, pair<int,int> b){
    ll distanceA = tinhBinhPhuongKhoangCachSoVoiGocToaDo(a);
    ll distanceB = tinhBinhPhuongKhoangCachSoVoiGocToaDo(b);
    if (distanceA < distanceB){
        return true;
    }
    else if (distanceA == distanceB){
        if (a.first < b.first){
            return true;
        }
        else if (a.first == b.first){
            return a.second < b.second;
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
    vector <pair <int, int> > a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), comp);
    for (int i = 0; i < n; i++){
        cout << a[i].first << ' ' << a[i].second << '\n';
    }
    return 0;
}