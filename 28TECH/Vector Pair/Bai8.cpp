#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<pair<int, int>,int>> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i].first.first;
        cin >> v[i].first.second;
        cin >> v[i].second;
    }
    vector<int> d(n);
    for (int i = 0; i < n; i++){
        int sum = 0;
        sum = v[i].first.first + v[i].first.second + v[i].second;
        d[i] = sum;
    }
    for (int i = 0; i < n; i++){
        cout << d[i] << ' ';
    }
}