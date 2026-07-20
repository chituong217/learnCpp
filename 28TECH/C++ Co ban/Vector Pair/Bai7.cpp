#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i].first;
        cin >> v[i].second;
    }
    vector<double> d(n);
    for (int i = 0; i < n; i++){
        double distance;
        distance = sqrt(pow(v[i].first, 2) + pow(v[i].second, 2));
        d[i] = distance;
    }
    for (int i = 0; i < n; i++){
        cout << fixed << setprecision(2) << d[i] << ' ';
    }
}