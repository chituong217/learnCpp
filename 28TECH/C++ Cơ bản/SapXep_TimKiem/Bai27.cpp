#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> se;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        se.insert(a[i]);
    }

    for (int i = 0; i < n; i++){
        auto it = se.upper_bound(a[i]);
        if (it != se.end()){
            a[i] = *it;
        }
        else{
            a[i] = '_';
        }
    }
    
    for (int i = 0; i < n; i++){
        if (a[i] == '_'){
            cout << (char)a[i] << ' ';
        }
        else{
            cout << a[i] << ' ';
        }
    }
    cout << endl;
    return 0;
}