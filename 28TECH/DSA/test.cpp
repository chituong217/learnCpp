#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(){
    int n;
    cin >> n;
    pair<int, int> p[n]; // mang cac pair
    for (int i = 0; i < n; i++){
        cin >> p[i].first >> p[i].second;
    }

    for (int i = 0; i < n; i++){
        cout << p[i].first << ' ' << p[i].second << endl;
    }
    return 0;
}