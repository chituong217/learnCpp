#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    multiset <int> se;
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        int tmp; cin >> tmp;
        se.insert(tmp);
    }

    int q; cin >> q;
    for (int i = 0; i < q; i++){
        int t; cin >> t;
        if (t == 1){
            int tmp; cin >> tmp;
            se.insert(tmp);
        }
        else if (t == 2){
            int x; cin >> x;
            if (se.find(x) != se.end()){
                auto it = se.find(x);
                se.erase(it);
            }
        }
        else if (t == 3){
            int x; cin >> x;
            if (se.find(x) != se.end()){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}