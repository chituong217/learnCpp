#include <set>
#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    multiset<int> se;
    for (int i = 0; i < n; i++){
        int tmp; cin >> tmp;
        se.insert(tmp);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++){
        int lc;
        cin >> lc;
        int x;
        cin >> x;
        if (lc == 1){
            se.insert(x);
        }
        else if (lc == 2){
            auto it = se.find(x);
            if (it != se.end()){
                se.erase(it);
            }
        }
        else if (lc == 3){
            bool found = false;
            for (auto it = se.begin(); it != se.end(); it++){
                if (*it >= x){
                    found = true;
                    cout << *it << endl;
                    break;
                }
            }

            if (found == false){
                cout << "-1\n";
            }
        }
        else if (lc == 4){
            bool found = false;
            for (auto it = se.rbegin(); it != se.rend(); it++){
                if (*it <= x){
                    found = true;
                    cout << *it << endl;
                    break;
                }
            }
            
            if (found == false){
                cout << "-1\n";
            }
        }
    }

    return 0;
}