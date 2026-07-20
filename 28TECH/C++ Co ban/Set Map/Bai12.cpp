#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m; cin >> n >> m;
    set<int> a;
    set<int> b;
    for (int i = 0; i < n; i++){
        int tmp; cin >> tmp;
        a.insert(tmp);
    }
    for (int i = 0; i < m; i++){
        int tmp; cin >> tmp;
        b.insert(tmp);
    }
    set<int> se;
    for (auto it = a.begin(); it != a.end(); it++){
        if (b.find(*it) == b.end()){
            se.insert(*it);
        }     
    }
    for (auto it = b.begin(); it != b.end(); it++){
        if (a.find(*it) == a.end()){
            se.insert(*it);
        }
    }
    for (auto it = se.begin(); it != se.end(); it++){
        cout << *it << ' ';
    }
    return 0;
}