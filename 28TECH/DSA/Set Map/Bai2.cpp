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

    set<int> se;
    for (int i = 0; i < n; i++){
        se.insert(a[i]);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++){
        int x;
        cin >> x;

        if (se.find(x) != se.end()){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    
    return 0;
}