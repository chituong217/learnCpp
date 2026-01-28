#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    multiset<int> se;
    for (int i = 0; i < n; i++){
        int tmp; cin >> tmp;
        se.insert(tmp);
    }
    int q; cin >> q;
    for (int i = 0; i < q; i++){
        int t; cin >> t;
        if (t == 1){
            int x; cin >> x;
            se.insert(x);
        }
        else if (t == 2){
            int x; cin >> x;
            if (se.find(x) != se.end()){
                se.erase(x);
            }
        }
        else if (t == 3){
            if (se.empty() == false){
                cout << (*se.begin()) << endl;
            }
        }
        else if (t == 4){
            if (se.empty() == false){
                cout << (*se.rbegin()) << endl;
            }
        }
    }
    return 0;
}