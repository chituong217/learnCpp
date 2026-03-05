#include <iostream>
#include <map>
#include <set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    int a[n], b[m];
    map<int, int> c, d;
    set<int> se;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        c[a[i]]++;
        se.insert(a[i]);
    }
    for (int i = 0; i < m; i++){
        cin >> b[i];
        d[b[i]]++;
        se.insert(b[i]);
    }

    for (auto it = c.begin(); it != c.end(); it++){
        if (d[(*it).first] > 0){
            cout << (*it).first << ' ';
        }
    }

    cout << endl;

    for (auto it = se.begin(); it != se.end(); it++){
        cout << *it << ' ';
    }

    return 0;
}