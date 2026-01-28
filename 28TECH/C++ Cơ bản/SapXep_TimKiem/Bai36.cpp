#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    multiset <int> gia;
    vector <int> khach(m);
    for (int i = 0; i < n; i++){
        int tmp; cin >> tmp;
        gia.insert(tmp);
    }
    for (int i = 0; i < m; i++){
        cin >> khach[i];
    }

    for (int i = 0; i < m; i++){
        if (gia.size() == 0){
            cout << "-1\n";
            continue;
        }
        auto find = gia.upper_bound(khach[i]);
        if (find == gia.begin()){
            cout << "-1\n";
        }
        else{
            find--;
            cout << *find << "\n";
            gia.erase(find);
        }
    }

    return 0;
}