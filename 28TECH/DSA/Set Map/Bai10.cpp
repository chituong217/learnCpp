#include <iostream>
#include <set>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int a[n];
    set<int> b;

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int i = 0; i < m; i++){
        int tmp; cin >> tmp;
        b.insert(tmp);
    }

    for (int i = 0; i < n; i++){
        auto it = b.find(a[i]);
        if (it != b.end()){
            cout << a[i] << ' ';
            b.erase(it);
        }
    }

    return 0;
}