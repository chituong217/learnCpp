#include <iostream>
#include <set>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int f[n];
    set<int> se;
    for (int i = n - 1; i >= 0; i--){
        se.insert(a[i]);
        f[i] = se.size();
    }

    int q;
    cin >> q;
    while (q--){
        int l;
        cin >> l;
        cout << f[l] << endl;
    }

    return 0;
}