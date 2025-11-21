#include <iostream>
#include <vector>

using namespace std;

int main(){
    int m; cin >> m;
    vector<int> v(m);
    for (int i = 0; i < m; i++){
        cin >> v[i];
    }

    int n; cin >> n;
    for (int i = 0; i < n; i++){
        int lc; cin >> lc;
        if (lc == 1){
            int k; cin >> k;
            int x; cin >> x;
            if (k >= 0 && k <= (int)v.size()){
                v.insert(v.begin() + k, x);
            }
        }
        else if (lc == 2){
            int k; cin >> k;

            if (k >= 0 && k < (int)v.size()){
                v.erase(v.begin() + k);
            }
        }
    }
    if (v.size() == 0){
        cout << "EMPTY";
        return 0;
    }
    for (int i = 0; i < (int)v.size(); i++){
        cout << v[i] << ' ';
    }
    return 0;
}