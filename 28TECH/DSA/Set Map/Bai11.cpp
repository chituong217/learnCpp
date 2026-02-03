#include <iostream>
#include <set>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
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

    for (auto it = a.begin(); it != a.end(); it++){
        if (b.find(*it) == b.end()){
            cout << *it << ' ';
        }
    }
    return 0;
}