#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    set<pair<int,int>> se;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        int y; cin >> y;
        se.insert({x, y});
    }
    cout << se.size();
    return 0;
}