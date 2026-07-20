#include <iostream>
#include <map>
#include <set>

using namespace std;

int a[1000000];
int f[1000000];

int main(){
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    set<int> se;
    for (int i = n-1; i >= 0; i--){
        se.insert(a[i]);
        f[i] = se.size();
    }

    int q; cin >> q;
    for (int i = 0; i < q; i++){
        int l; cin >> l;
        cout << f[l] << endl;
    }

    return 0;
}