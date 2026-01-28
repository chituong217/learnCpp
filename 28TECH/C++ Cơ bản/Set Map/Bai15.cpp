#include <iostream>
#include <map>
#include <set>

using namespace std;

int main(){
    int n; cin >> n;
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
                auto it = se.find(x);
                se.erase(it);
            }
        }
        else if (t == 3){
            int x; cin >> x;
            auto dau = se.rend();
            if (se.empty() == false){
                dau--;
            }
            bool found = false;
            for (auto it = se.rbegin(); it != se.rend(); it++){
                if (*it < x){
                    if (it == se.rbegin()){
                        found = false;
                        break;
                    }
                    it--;
                    cout << *it << endl;
                    found = true;
                    break;
                }
                if (it == dau){
                    cout << *it << endl;
                    found = true;
                    break;
                }
            }
            if (found == false){
                cout << "-1" << endl;
            }
        }
        else if (t == 4){
            int x; cin >> x;
            bool found = false;
            auto cuoi = se.end();
            if (se.empty() == false){\
                cuoi--;
            }
            
            for (auto it = se.begin(); it != se.end(); it++){
                if (*it > x){
                    if (it == se.begin()){
                        found = false;
                        break;
                    }
                    it--;
                    cout << *it << endl;
                    found = true;
                    break;
                }
                if (it == cuoi){
                    found = true;
                    cout << *it << endl;
                    break;
                }
            }
            if (found == false){
                cout << "-1" << endl;
            }
        }
    }
    return 0;
}