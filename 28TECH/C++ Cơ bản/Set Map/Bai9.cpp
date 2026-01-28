#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    int m; cin >> m;
    set<int> se;
    for (int i = 0; i < n+m; i++){
        int tmp; cin >> tmp;
        se.insert(tmp);
    }
    for (auto it = se.rbegin(); it != se.rend(); it++){
        cout << *it << ' ';
    }
    return 0;
}