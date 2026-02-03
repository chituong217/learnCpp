#include <iostream>
#include <set>

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
        int tmp;
        cin >> tmp;

        if (tmp == 1){
            int x;
            cin >> x;
            se.insert(x);
        }
        else if (tmp == 2){
            int x;
            cin >> x;
            se.erase(x);
        }
        else if (tmp == 3){
            cout << *se.begin() << endl;
        }
        else{
            cout << *se.rbegin() << endl;
        }
    }

    return 0;
}