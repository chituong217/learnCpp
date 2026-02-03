#include <iostream>
#include <set>

using namespace std;

int main(){
    int n;
    cin >> n;
    multiset<int> se;
    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        se.insert(tmp);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++){
        int lc;
        cin >> lc;
        if (lc == 1){
            int x;
            cin >> x;
            se.insert(x);
        }
        else if (lc == 2){
            int x;
            cin >> x;
            auto it = se.find(x);

            if (it != se.end()){
                se.erase(it);
            }
        }
        else if (lc == 3){
            int x;
            cin >> x;
            auto it = se.find(x);
            if (it != se.end()){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
    }

    return 0;
}